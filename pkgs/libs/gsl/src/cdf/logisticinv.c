/* cdf/logisticinv.c
 * 
 * Copyright (C) 2003 Brian Gough
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include <config.h>
#include <math.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_cdf.h>

double
gsl_cdf_logistic_Pinv (const double P, const double a)
{
  double x;

  if (P == 1.0)
    {
      return GSL_POSINF;
    }
  else if (P == 0.0)
    {
      return GSL_NEGINF;
    }

  x = a * log(P/(1-P));

  return x;
}

double
gsl_cdf_logistic_Qinv (const double Q, const double a)
{
  double x;

  if (Q == 0.0)
    {
      return GSL_POSINF;
    }
  else if (Q == 1.0)
    {
      return GSL_NEGINF;
    }

  x = a * log((1-Q)/Q);

  return x;
}
