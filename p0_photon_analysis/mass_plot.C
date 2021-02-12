
void mass_plot(TString MBntup, TString ERTntup) {
  TFile* f1 = new TFile(MBntup);
  TFile* f2 = new TFile(ERTntup);

  TCanvas *canvas  = new TCanvas("canvas",  "pi0 and gammas", 900, 900);
  canvas->Divide(1,3);

  //  f1->ls();
  f1->cd();
  canvas_1->Divide(2,1);
  canvas_2->Divide(2,1);
  canvas_1_1->cd();
  ggntuple->Draw("mass","mass<1.0");

  f2->cd();
  canvas_1_2->cd();
  ggntuple->Draw("mass","mass<1.0");

  f1->cd();
  canvas_2_1->cd();
  ggntuple->Draw("mass>>htemp1","mass<1.0");
  canvas_2_2->cd();
  ggntuple->Draw("mass>>htemp2","mass<1.0&&chisq1<3.0&&chisq2<3.0");
  
  canvas_3->SetLogy();
  canvas_3->cd();

  htemp2->SetLineColor(2);
  htemp1->Draw();
  htemp2->Draw("same");
}
