// --------------------------------------------------------------
// This macro is intended to be used with ROOT files prepared
// for the PHENIX Collaboration document titled
// "Neutral meson and photon ntuples: explanation and examples".
//
// NB. This version is written for ROOT5
//
// The files are: MBntup_gnt.root and ERTntup_gnt.root
// They contain the so-called "single cluster ntuple" referred to
// as ggntuple in the code below.
//
// The first argument selects a segment within the macro corresponding
// to plots and code snippets in the document. Valid choices are:
//
// position
// ecore
// chisq
//
// For exact semantics of each choice please see the PDF document
// --------------------------------------------------------------
void single_cluster_r5(TString option, TString MBntup="MBntup_gnt.root", TString ERTntup="ERTntup_gnt.root") {
  TFile* mb = new TFile(MBntup);
  TFile* ert = new TFile(ERTntup);

  int W=1200;
  int H=400;

  if (option=="position") { // ############ position
    TCanvas *canvas1  = new TCanvas("canvas1",  "Cluster position", W, H);
    canvas1->Divide(2,1);

    mb->cd();
    canvas1_1->cd();
    gnt->Draw("y:z","sec==1","colz");

    ert->cd();
    canvas1_2->cd();
    gnt->Draw("y:z","sec==1","colz");
  }
  elseif (option=="ecore") {  // ########### ecore
    mb->cd();
    TCanvas *canvas2  = new TCanvas("canvas2",  "ecent/ecore:ecore", 3*W/2, H);
    canvas2->Divide(3,1);

    mb->cd();
    canvas2_1->cd();
    gnt->Draw("ecent/ecore:ecore","ecore<4.0","colz");

    canvas2_2->cd();
    gnt->Draw("ecent/ecore:ecore","ecore<4.0 && chisq<3.0","colz");

    canvas2_3->cd();
    gnt->Draw("ecent/ecore:ecore","ecore<4.0 && chisq>5.0","colz");
  }
  elseif (option=="chisq") {  // ############ chisq
    TCanvas *canvas3  = new TCanvas("canvas3",  "chi*82 cut", W, H*2);
    canvas3->cd();
    canvas3->SetLogy();
    ert->cd();

    TH1D *h1 = new TH1D("h1","h1",100,0.0,50.0);
    TH1D *h2 = new TH1D("h2","h2",100,0.0,50.0);
    h1->SetLineWidth(2.0);
    h2->SetLineWidth(2.0);
    h2->SetLineColor(2);
    gnt->Draw("pt>>h1","");
    gnt->Draw("pt>>h2","chisq<3.0");
    h1->Draw();
    h2->Draw("same");    
  }
}
