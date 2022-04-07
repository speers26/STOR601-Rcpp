// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// fund
CharacterVector fund(DataFrame male_pref2, DataFrame female_pref2);
RcppExport SEXP _StableMarriageMatt_fund(SEXP male_pref2SEXP, SEXP female_pref2SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< DataFrame >::type male_pref2(male_pref2SEXP);
    Rcpp::traits::input_parameter< DataFrame >::type female_pref2(female_pref2SEXP);
    rcpp_result_gen = Rcpp::wrap(fund(male_pref2, female_pref2));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_StableMarriageMatt_fund", (DL_FUNC) &_StableMarriageMatt_fund, 2},
    {NULL, NULL, 0}
};

RcppExport void R_init_StableMarriageMatt(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
