{
  //Need this to allow ROOT to be able to use a SiElectronTSelector
  gSystem->Load("libFWCoreFWLite");
  AutoLibraryLoader::enable();
  //Have to load library manually since Proof does not use the 
  // mechanism used by TFile to find class dictionaries and therefore
  // the AutoLibraryLoader can not help
  gSystem->Load("libRecoEgammaEgammaElectronProducersTest");

  TSelector* sel = new tfwliteselectortest::SiElectronTSelector();
  
  //This holds the list of files and 'TTree' to process
  TChain c("Events");
  c.Add("eventdata.root");

  //This actually processes the data
  c.Process(sel);
}
