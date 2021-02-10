void mass_plot() {
  TFile* f1 = new TFile("MBntup.root");
  TFile* f2 = new TFile("ERTntup.root");
  
  f1->cd();
  ggntuple->Draw("mass","mass<1.0");

  f2->cd();
  ggntuple->Draw("mass","mass<1.0");

  f1->cd();
  ggntuple->Draw("mass>>htemp1","mass<1.0");
  ggntuple->Draw("mass>>htemp2","mass<0.4&&chisq1<3.0&&chisq2<3.0");
  
  htemp2->SetLineColor(2);
  htemp1->Draw();
  htemp2->Draw("same");
}
