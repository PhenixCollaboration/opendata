// --------------------------------------------------------------
// This macro is intended to be used with ROOT files prepared
// for the PHENIX Collaboration document titled
// "Neutral meson and photon ntuples: explanation and examples".
//
// NB. This version is written for ROOT6
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

  TNtuple *ggntuple_mb  = (TNtuple*)mb->Get("ggntuple");
  TNtuple *ggntuple_ert = (TNtuple*)ert->Get("ggntuple");

  int W=900;
  int H=400;

  if (option=="chi2") { // ############ chi2
    TCanvas *canvas1  = new TCanvas("canvas1",  "Effect of the chi2 cut", W, H*3);
    canvas1->Divide(1,3);

    canvas1->GetPad(1)->Divide(2,1);
    canvas1->GetPad(2)->Divide(2,1);
    
    canvas1->cd(1)->cd(1);
    ggntuple_mb->Draw("mass","mass<1.0");

    canvas1->cd(1)->cd(2);
    ggntuple_ert->Draw("mass","mass<1.0");

    canvas1->cd(2)->cd(1);
    ggntuple_mb->Draw("mass>>htemp1","mass<1.0");

    canvas1->cd(2)->cd(2);
    ggntuple_mb->Draw("mass>>htemp2","mass<1.0 && chisq1<3.0 && chisq2<3.0");
  
    canvas1->GetPad(3)->SetLogy();
    canvas1->cd(3);

    TH1* htemp1 = (TH1*) gDirectory->Get("htemp1");
    TH1* htemp2 = (TH1*) gDirectory->Get("htemp2");

    htemp2->SetLineColor(2);
    htemp1->Draw();
    htemp2->Draw("same");
  }
 else if (option=="asymmetry") {  // ########### asymmetry
   TCanvas *canvas2  = new TCanvas("canvas2",  "Effect of the asymmetry cut", W, H);
   canvas2->Divide(2,1);
   canvas2->cd(1);
   ggntuple_mb->Draw("asym","mass<1.0");

   canvas2->cd(2);
   canvas2->GetPad(2)->SetLogy();
   ggntuple_mb->Draw("mass>>htemp3","mass<0.5");
   ggntuple_mb->Draw("mass>>htemp4","mass<0.5 && asym<0.6");

   TH1* htemp3 = (TH1*) gDirectory->Get("htemp3");
   TH1* htemp4 = (TH1*) gDirectory->Get("htemp4");
   
   htemp4->SetLineColor(2);
   htemp3->Draw();
   htemp4->Draw("same");
 }
 else if (option=="pt") {  // ############ pt
   TCanvas *canvas3  = new TCanvas("canvas3",  "pt spectra", W, H*2);
   canvas3->Divide(1,2);
   canvas3->GetPad(1)->Divide(2,1);

   canvas3->cd(1)->cd(1);
   canvas3->GetPad(1)->GetPad(1)->SetLogy();
 
   ggntuple_mb->Draw("pt>>htemp5","abs(mass-0.135)<0.015");
   ggntuple_mb->Draw("pt>>htemp6","abs(mass-0.135)<0.015 && chisq1<3.0 && chisq2<3.0");
    
   TH1* htemp5 = (TH1*) gDirectory->Get("htemp5");
   TH1* htemp6 = (TH1*) gDirectory->Get("htemp6");
  
   htemp5->Draw();
   htemp6->SetLineColor(2);
   htemp6->Draw("same");

   canvas3->cd(1)->cd(2);
   canvas3->GetPad(1)->GetPad(2)->SetLogy();
   ggntuple_ert->Draw("pt>>htemp7","abs(mass-0.135)<0.015");
   ggntuple_ert->Draw("pt>>htemp8","abs(mass-0.135)<0.015 && chisq1<3.0 && chisq2<3.0");
   
   TH1* htemp7 = (TH1*) gDirectory->Get("htemp7");
   TH1* htemp8 = (TH1*) gDirectory->Get("htemp8");
   
   htemp7->Draw();
   htemp8->SetLineColor(2);
   htemp8->Draw("same");

   canvas3->cd(2);
   canvas3->GetPad(2)->SetLogy();
   
   ggntuple_ert->Draw("pt>>htemp9", "abs(mass-0.548)<0.1");
   ggntuple_ert->Draw("pt>>htemp10","abs(mass-0.548)<0.1 && chisq1<3.0 && chisq2<3.0");

   TH1* htemp9 = (TH1*) gDirectory->Get("htemp9");
   TH1* htemp10= (TH1*) gDirectory->Get("htemp10");
   
   htemp9->Draw();
   htemp10->SetLineColor(2);
   htemp10->Draw("same");
 }
 else if (option=="tof") {  // ########### tof
  TCanvas *canvas4  = new TCanvas("canvas4",  "Effect of the TOF cut", W, H);
  canvas4->Divide(2,1);
  canvas4->cd(1);
  canvas4->GetPad(1)->SetLogz();
  ggntuple_mb->Draw("tof1:tof2","abs(mass-0.135)<0.015 && abs(tof1)<20.0&& abs(tof2)<20.0","colz");

  canvas4->cd(2);
  canvas4->GetPad(2)->SetLogy();

  TH1D *hsmall = new TH1D("hsmall","hsmall",50,0.0,50.0);
  TH1D *hlarge = new TH1D("hlarge","hlarge",50,0.0,50.0);
  
  ggntuple_mb->Draw("chisq1>>hsmall","abs(mass-0.135)<0.015&&abs(tof1)<3.0&&abs(tof2)>5.0");
  ggntuple_mb->Draw("chisq2>>hlarge","abs(mass-0.135)<0.015&&abs(tof1)<3.0&&abs(tof2)>5.0");

  hlarge->SetLineColor(2);
  hlarge->SetLineWidth(2);
  
  hsmall->SetLineWidth(2);
  hsmall->Draw();
  hlarge->Draw("same");
 }
}

