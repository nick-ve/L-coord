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

 // The Westerbork radio telescope
 lab.SetExperiment("WSRT");
 lab.SetTAI("UTC","06-09-2011","21:10:34.7",0,"A",0);
 lab.Data(1,"dms"); // Print laboratory parameters

 // Enter the object to be investigated
 Float_t alpha=4242.;
 Float_t delta=411600.;
 lab.SetSignal(1,alpha,"hms",delta,"dms","equ",0,-1,"J","M31");

 // Print the signal info for the timestamp at the observation
 cout << endl;
 lab.PrintSignal("hor","T",0,5,"M31");
 cout << endl;
 cout << " ----------------------" << endl;
 lab.PrintSignal("equ","J",0,5,"M31");
 cout << endl;
 cout << " ----------------------" << endl;
 lab.PrintSignal("equ","M",0,5,"M31");
 cout << endl;
 cout << " ----------------------" << endl;
 lab.PrintSignal("equ","T",0,5,"M31");
 cout << endl;
 cout << " ----------------------" << endl;
 lab.PrintSignal("gal","M",0,5,"M31");
 cout << endl;
 cout << " ----------------------" << endl;

 // Display the object on a skymap
// lab.DisplaySignal("hor","M",0,"M31","ham");
// lab.DisplaySignal("equ","M",0,"M31","ham");
 lab.DisplaySignal("gal","M",0,"M31","ham");
}