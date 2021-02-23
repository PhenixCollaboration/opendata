# Introduction to pi0 and photon analysis in PHENIX

This packages contains description of data and code samples illustrating
a few basic techniques of neutral meson and photon analysis in PHENIX
A set of Ntuples derived from actual PHENIX data to be used within the context of
this exercise is provided separately.

* pi0ntup_v1 - the original "preview" version of the write-up based on files containing different types of ntuples; also requires "revtex" so won't compule on some systems.
* pi0ntup_v2 - simpler TeX code, take into account refactored Ntuples and ROOT macros
* gamma_gamma.C - a ROOT macro to use with gamma-gamma Ntuples
* single_cluster.C - a ROOT macro to use with single cluster Ntuples

Caveat - the current version of macros only work under ROOT5. A Docker image
of ROOT5 can be obtained from phenixcollaboration/tools:sl7_root5 on Docker Hub.




