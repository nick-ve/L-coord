///////////////////////////////////////////////////
// ROOT macro to test NcAstrolab functionality
//
// Nick van Eijndhoven, 23-jun-2011, IIHE Brussel 
///////////////////////////////////////////////////
{
 gSystem->Load("ncfspack");

 NcAstrolab lab;

 // Load the IERS data files for the UTC parameters
 lab.LoadUTCparameterFiles("leap.txt","dut.txt");

 // The IceCube experiment
 lab.SetExperiment("IceCube");
 lab.SetTAI("UTC","15-08-2009","06:23:16.2",0,"A",0);
 lab.Data(1,"dms"); // Print laboratory parameters

 // Enter the observed IceCube event to be investigated
 Nc3Vector r;
 r.SetVector(1,12,138,"sph","deg");
 r*=-1; // We need to investigate the origin
 Float_t theta=r.GetX(2,"sph","deg");
 Float_t phi=r.GetX(3,"sph","deg");
 lab.SetSignal(1,theta,"deg",phi,"deg","loc",0,-1,"T","Muon",1);

 // Print the signal info for the timestamp at the observation
 cout << endl;
 lab.PrintSignal("loc","T",0,5,"Muon","T",1);
 cout << endl;
 cout << " ----------------------" << endl;
 lab.PrintSignal("equ","J",0,5,"Muon","T",1);
 cout << endl;
 cout << " ----------------------" << endl;
 lab.PrintSignal("equ","M",0,5,"Muon","T",1);
 cout << endl;
 cout << " ----------------------" << endl;
 lab.PrintSignal("equ","T",0,5,"Muon","T",1);
 cout << endl;
 cout << " ----------------------" << endl;
 lab.PrintSignal("gal","T",0,5,"Muon","T",1);
 cout << endl;
 cout << " ----------------------" << endl;

// lab.DisplaySignal("equ","J",0,"Muon","ham",0,1);
// lab.DisplaySignal("gal","T",0,"Muon","ham",0,1);
 lab.DisplaySignal("loc","T",0,"Muon","ham",0,1);
 }