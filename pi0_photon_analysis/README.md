# Introduction to pi0 and photon analysis in PHENIX

This packages contains a description of data and code samples illustrating
a few basic techniques of neutral meson and photon analysis in PHENIX.

A set of Ntuples derived from actual PHENIX data to be used within the
context of this exercise is provided separately.

* pi0ntup_v1 - the original "preview" version of the write-up based on files containing
different types of ntuples; also requires "revtex" so the TeX source won't compile on some systems.
* pi0ntup_v2 - simplified TeX source, takes into account refactored Ntuples and ROOT macros
* gamma_gamma*.C - ROOT macros to use with gamma-gamma Ntuples (for ROOT5 and ROOT6)
* single_cluster*.C - ROOT macroa to use with single cluster Ntuples (for ROOT5 and ROOT6)

ROOT5 versions are the original and were created due to the fact that most PHENIX
analyses are done with the legacy ROOT version. Docker image
of ROOT5 can be obtained from phenixcollaboration/tools:sl7_root5 on Docker Hub.

ROOT6 macros are functionally equivalent.




