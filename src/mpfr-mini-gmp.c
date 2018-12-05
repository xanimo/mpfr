/* mpfr-mini-gmp.c -- Interface functions for mini-gmp.

Copyright 2014-2018 Free Software Foundation, Inc.
Contributed by the AriC and Caramba projects, INRIA.

This file is part of the GNU MPFR Library.

The GNU MPFR Library is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or (at your
option) any later version.

The GNU MPFR Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
License for more details.

You should have received a copy of the GNU Lesser General Public License
along with the GNU MPFR Library; see the file COPYING.LESSER.  If not, see
http://www.gnu.org/licenses/ or write to the Free Software Foundation, Inc.,
51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA. */

/* The following include will do 2 things: include the config.h
   if there is one (as it may define MPFR_USE_MINI_GMP), and avoid
   an empty translation unit (see ISO C99, 6.9). */
#include "mpfr-impl.h"

#ifdef MPFR_USE_MINI_GMP

/************************ random generation functions ************************/

#ifdef WANT_gmp_randinit_default
void
gmp_randinit_default (gmp_randstate_t state)
{
}
#endif

#ifdef WANT_gmp_randseed_ui
void
gmp_randseed_ui (gmp_randstate_t state, unsigned long int seed)
{
  srand48 (seed);
}
#endif

#ifdef WANT_gmp_randclear
void
gmp_randclear (gmp_randstate_t state)
{
}
#endif

#ifdef WANT_gmp_randinit_set
void
gmp_randinit_set (gmp_randstate_t s1, gmp_randstate_t s2)
{
}
#endif

static mp_limb_t
random_limb (void)
{
  /* lrand48() only gives 31 bits */
#if GMP_NUMB_BITS == 8 || GMP_NUMB_BITS == 16
  return (mp_limb_t) lrand48 ();
#elif GMP_NUMB_BITS == 32
  return lrand48 () + (lrand48 () << 31);
#elif GMP_NUMB_BITS == 64
  return lrand48 () + (((mp_limb_t) lrand48 ()) << 31)
    + (((mp_limb_t) lrand48 ()) << 62);
#else
#error "GMP_NUMB_BITS should be 8, 16, 32 or >= 64"
#endif
}

#ifdef WANT_mpz_urandomb
void
mpz_urandomb (mpz_t rop, gmp_randstate_t state, mp_bitcnt_t nbits)
{
  unsigned long n, i;

  mpz_realloc2 (rop, nbits);
  n = (nbits - 1) / GMP_NUMB_BITS + 1; /* number of limbs */
  for (i = n; i-- > 0;)
    rop->_mp_d[i] = random_limb ();
  i = n * GMP_NUMB_BITS - nbits;
  /* mask the upper i bits */
  if (i)
    rop->_mp_d[n-1] = MPFR_LIMB_LSHIFT(rop->_mp_d[n-1], i) >> i;
  while (n > 0 && (rop->_mp_d[n-1] == 0))
    n--;
  rop->_mp_size = n;
}
#endif

#ifdef WANT_gmp_urandomm_ui
unsigned long
gmp_urandomm_ui (gmp_randstate_t state, unsigned long n)
{
  mp_limb_t p, q;
  unsigned long r;

  MPFR_ASSERTN (n > 0);
#ifndef MPFR_LONG_WITHIN_LIMB
  /* The method below generates a random limb, it can thus only work when
     n <= MPFR_LIMB_MAX + 1. FIXME: write a method that works in all cases */
  MPFR_ASSERTN (n - 1 <= MPFR_LIMB_MAX);
#endif
  p = random_limb (); /* p is in [0, MPFR_LIMB_MAX], thus p is uniform among
                         MPFR_LIMB_MAX+1 values */
  r = MPFR_LIMB_MAX % n;
  if (r < n - 1) /* MPFR_LIMB_MAX+1 is not multiple of n */
    {
      q = n * (MPFR_LIMB_MAX / n);
      while (p >= q)
        p = random_limb ();
    }
  return p % n;
}
#endif

#ifdef WANT_gmp_urandomb_ui
unsigned long
gmp_urandomb_ui (gmp_randstate_t state, unsigned long n)
{
#ifdef MPFR_LONG_WITHIN_LIMB
  return random_limb () % (1UL << n);
#else
  unsigned long res = 0;
  int m = n; /* remaining bits to generate */
  while (m >= GMP_NUMB_BITS)
    {
      /* we can generate a full limb */
      res = (res << GMP_NUMB_BITS) | (unsigned long) random_limb ();
      m -= GMP_NUMB_BITS;
    }
  /* now m < GMP_NUMB_BITS */
  if (m) /* generate m extra bits */
    res = (res << m) | (unsigned long) (random_limb () % (1UL << m));
  return res;
#endif
}
#endif

/************************* division functions ********************************/

#ifdef WANT_mpn_divrem_1
mp_limb_t
mpn_divrem_1 (mp_limb_t *qp, mp_size_t qxn, mp_limb_t *np, mp_size_t nn,
              mp_limb_t d0)
{
  mpz_t q, r, n, d;
  mp_limb_t ret, dd[1];

  d->_mp_d = dd;
  d->_mp_d[0] = d0;
  d->_mp_size = 1;
  mpz_init (q);
  mpz_init (r);
  if (qxn == 0)
    {
      n->_mp_d = np;
      n->_mp_size = nn;
    }
  else
    {
      mpz_init2 (n, (nn + qxn) * GMP_NUMB_BITS);
      mpn_copyi (n->_mp_d + qxn, np, nn);
      mpn_zero (n->_mp_d, qxn);
      n->_mp_size = nn + qxn;
    }
  mpz_tdiv_qr (q, r, n, d);
  if (q->_mp_size > 0)
    mpn_copyi (qp, q->_mp_d, q->_mp_size);
  if (q->_mp_size < nn + qxn)
    mpn_zero (qp + q->_mp_size, nn + qxn - q->_mp_size);
  ret = (r->_mp_size == 1) ? r->_mp_d[0] : 0;
  mpz_clear (q);
  mpz_clear (r);
  if (qxn != 0)
    mpz_clear (n);
  return ret;
}
#endif

#ifdef WANT_mpn_divrem
mp_limb_t
mpn_divrem (mp_limb_t *qp, mp_size_t qn, mp_limb_t *np,
            mp_size_t nn, const mp_limb_t *dp, mp_size_t dn)
{
  mpz_t q, r, n, d;
  mp_limb_t ret;

  MPFR_ASSERTN(qn == 0);
  qn = nn - dn;
  n->_mp_d = np;
  n->_mp_size = nn;
  d->_mp_d = (mp_limb_t*) dp;
  d->_mp_size = dn;
  mpz_init (q);
  mpz_init (r);
  mpz_tdiv_qr (q, r, n, d);
  MPFR_ASSERTN(q->_mp_size == qn || q->_mp_size == qn + 1);
  mpn_copyi (qp, q->_mp_d, qn);
  ret = (q->_mp_size == qn) ? 0 : q->_mp_d[qn];
  if (r->_mp_size > 0)
    mpn_copyi (np, r->_mp_d, r->_mp_size);
  if (r->_mp_size < dn)
    mpn_zero (np + r->_mp_size, dn - r->_mp_size);
  mpz_clear (q);
  mpz_clear (r);
  return ret;
}
#endif

#ifdef WANT_mpn_tdiv_qr
void
mpn_tdiv_qr (mp_limb_t *qp, mp_limb_t *rp, mp_size_t qxn,
             const mp_limb_t *np, mp_size_t nn,
             const mp_limb_t *dp, mp_size_t dn)
{
  mpz_t q, r, n, d;

  MPFR_ASSERTN(qxn == 0);
  n->_mp_d = (mp_limb_t*) np;
  n->_mp_size = nn;
  d->_mp_d = (mp_limb_t*) dp;
  d->_mp_size = dn;
  mpz_init (q);
  mpz_init (r);
  mpz_tdiv_qr (q, r, n, d);
  MPFR_ASSERTN(q->_mp_size > 0);
  mpn_copyi (qp, q->_mp_d, q->_mp_size);
  if (q->_mp_size < nn - dn + 1)
    mpn_zero (qp + q->_mp_size, nn - dn + 1 - q->_mp_size);
  if (r->_mp_size > 0)
    mpn_copyi (rp, r->_mp_d, r->_mp_size);
  if (r->_mp_size < dn)
    mpn_zero (rp + r->_mp_size, dn - r->_mp_size);
  mpz_clear (q);
  mpz_clear (r);
}
#endif

#if 0 /* this function is useful for debugging, thus please keep it here */
void
mpz_dump (mpz_t z)
{
  mp_size_t n = z->_mp_size;

  MPFR_STAT_STATIC_ASSERT ((GMP_NUMB_BITS % 4) == 0);

  if (n == 0)
    printf ("0");
  else
    {
      int first = 1;
      if (n < 0)
        {
          printf ("-");
          n = -n;
        }
      while (n > 0)
        {
          if (first)
            {
              printf ("%lx", (unsigned long) z->_mp_d[n-1]);
              first = 0;
            }
          else
            {
              char s[17];
              int len;
              sprintf (s, "%lx", (unsigned long) z->_mp_d[n-1]);
              len = strlen (s);
              /* one character should be printed for 4 bits */
              while (len++ < GMP_NUMB_BITS / 4)
                printf ("0");
              printf ("%lx", (unsigned long) z->_mp_d[n-1]);
            }
          n--;
        }
    }
  printf ("\n");
}
#endif

#endif /* MPFR_USE_MINI_GMP */
