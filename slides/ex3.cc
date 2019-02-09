///////////////////////////////////////////////////
// ROOT macro to test NcAstrolab functionality
//
// Nick van Eijndhoven, 23-jun-2011, IIHE Brussel 
///////////////////////////////////////////////////
{
 gSystem->Load("ncfspack");

 NcAstrolab lab;

 // The IceCube experiment
 lab.SetExperiment("IceCube");
 lab.Data(1,"dms"); // Print laboratory parameters

 // Enter some random cosmic rays via an isotropic distribution
 Int_t n=1000;
 NcRandom rndm;
 TString name;
 Double_t pi=acos(-1.);
 Float_t theta,phi,cost,alpha,delta;
 for (Int_t i=1; i<=n; i++)
 {
  phi=rndm.Uniform(0.,360.);
  cost=rndm.Uniform(-1.,1.);
  theta=acos(cost);
  alpha=phi;
  delta=pi/2.-theta;
  name="X";
  name+=i;
//  lab.SetSignal(1,alpha,"deg",delta,"rad","equ",0,-1,"J",name,1);
  lab.SetSignal(1,theta,"rad",phi,"deg","loc",0,-1,"M",name,1);
//  lab.SetSignal(1,phi,"deg",theta,"rad","hor",0,-1,"M",name,1);
 } 

// lab.DisplaySignals("equ","J",0,"ham",1);
// lab.DisplaySignals("equ","J",0,"angh",1);
 lab.DisplaySignals("gal","T",0,"ham",1);
 }
