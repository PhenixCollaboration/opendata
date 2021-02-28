// --------------------------------------------------------------
// This macro is intended to be used with ROOT files prepared
// for the PHENIX Collaboration document titled
// "Neutral meson and photon ntuples: explanation and examples".
// 
// The files are: MBntup_ggntuple.root and ERTntup_ggntuple.root
// They contain the so-called "gamma-gamma ntuple" referred to
// as ggntuple in the code below.
//
// The first argument selects a segment within the macro corresponding
// to plots and code snippets in the document. Valid choices are:
//
// chi2
// assymmetry
// pt
// tof
//
// For exact semantics of each choice please see the PDF document
// --------------------------------------------------------------
void gamma_gamma(TString option, TString MBntup="MBntup_ggntuple.root", TString ERTntup="ERTntup_ggntuple.root") {
  TFile* mb = new TFile(MBntup);
  TFile* ert = new TFile(ERTntup);

  // Chi**2

  int W=900;
  int H=400;

  if (option=="chi2") { // ############ chi2
    TCanvas *canvas1  = new TCanvas("canvas1",  "Effect of the chi2 cut", W, H*3);
    canvas1->Divide(1,3);

    canvas1_1->Divide(2,1);
    canvas1_2->Divide(2,1);

    mb->cd();
    canvas1_1_1->cd();
    ggntuple->Draw("mass","mass<1.0");

    ert->cd();
    canvas1_1_2->cd();
    ggntuple->Draw("mass","mass<1.0");

    mb->cd();
    canvas1_2_1->cd();
    ggntuple->Draw("mass>>htemp1","mass<1.0");
    canvas1_2_2->cd();
    ggntuple->Draw("mass>>htemp2","mass<1.0 && chisq1<3.0 && chisq2<3.0");
  
    canvas1_3->SetLogy();
    canvas1_3->cd();

    htemp2->SetLineColor(2);
    htemp1->Draw();
    htemp2->Draw("same");
  }
  elseif (option=="asymmetry") {  // ########### asymmetry
    mb->cd();
    TCanvas *canvas2  = new TCanvas("canvas2",  "Effect of the asymmetry cut", W, H);
    canvas2->Divide(2,1);
    canvas2_1->cd();
    ggntuple->Draw("asym","mass<1.0");

    canvas2_2->cd();
    canvas2_2->SetLogy();
    ggntuple->Draw("mass>>htemp3","mass<0.5");
    ggntuple->Draw("mass>>htemp4","mass<0.5 && asym<0.6");

    htemp4->SetLineColor(2);
    htemp3->Draw();
    htemp4->Draw("same");
  }
  elseif (option=="pt") {  // ############ pt
    TCanvas *canvas3  = new TCanvas("canvas3",  "pt spectra", W, H*2);
    canvas3->Divide(1,2);
    canvas3_1->Divide(2,1);

    mb->cd();
    canvas3_1_1->cd();
    canvas3_1_1->SetLogy();
    ggntuple->Draw("pt>>htemp5","abs(mass-0.135)<0.015");
    ggntuple->Draw("pt>>htemp6","abs(mass-0.135)<0.015 && chisq1<3.0 && chisq2<3.0");
    htemp6->SetLineColor(2);
    htemp5->Draw();
    htemp6->Draw("same");

    ert->cd();
    canvas3_1_2->cd();
    canvas3_1_2->SetLogy();
    ggntuple->Draw("pt>>htemp7","abs(mass-0.135)<0.015");
    ggntuple->Draw("pt>>htemp8","abs(mass-0.135)<0.015 && chisq1<3.0 && chisq2<3.0");
    htemp8->SetLineColor(2);
    htemp7->Draw();
    htemp8->Draw("same");

    canvas3_2->cd();
    canvas3_2->SetLogy();
    ggntuple->Draw("pt>>htemp9","abs(mass-0.548)<0.1");
    ggntuple->Draw("pt>>htemp10","abs(mass-0.548)<0.1 && chisq1<3.0 && chisq2<3.0");
    htemp10->SetLineColor(2);
    htemp9->Draw();
    htemp10->Draw("same");
  }
  elseif (option=="tof") {  // ########### tof
    mb->cd();
    TCanvas *canvas4  = new TCanvas("canvas4",  "Effect of the TOF cut", W, H);
    canvas4->Divide(2,1);
    canvas4_1->cd();
    canvas4_1->SetLogz();
    ggntuple->Draw("tof1:tof2","abs(mass-0.135)<0.015 && abs(tof1)<20.0&& abs(tof2)<20.0","colz");

    canvas4_2->cd();
    canvas4_2->SetLogy();
    TH1D *hsmall = new TH1D("hsmall","hsmall",50,0.0,50.0);
    TH1D *hlarge = new TH1D("hlarge","hlarge",50,0.0,50.0);
    ggntuple->Draw("chisq1>>hsmall","abs(mass-0.135)<0.015&&abs(tof1)<3.0&&abs(tof2)>5.0");
    ggntuple->Draw("chisq2>>hlarge","abs(mass-0.135)<0.015&&abs(tof1)<3.0&&abs(tof2)>5.0");
    hlarge->SetLineColor(2);
    hlarge->SetLineWidth(2);
    hsmall->SetLineWidth(2);
    hsmall->Draw();
    hlarge->Draw("same");
  }


}
