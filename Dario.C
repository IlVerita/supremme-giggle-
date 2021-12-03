{
TRandom3 rnd;
rnd.SetSeed(12345678);

int ntot   = 6000;        //numero totale di iterazioni
double dim = sqrt(3);
int d      = 0;              //spostamento rispetto all'origine in 1D
double tau = 0.05;
h1 = TH1D("h", "", 100, -3, 3);
//h2 = TH2D("h", "", 100, 0, 0, 100, 0, 0);
TGraphErrors gr;

for(int i=0; i<ntot; i++){
	
	//double u     = -TMath::Log(1-rnd.Rndm());   //rnd.Rndm() ha la funzione di eta nelle slide
    //double theta = rnd.Rndm()*2*TMath::Pi();              //generata in maniera uniforme tra 0 e 2*pi
    //double r     = sqrt(2*u);                        //inversione di u = r^2/2
    //double x     = r*cos(theta);         	
    //double x     = r*cos(theta);         	
	
	double x = sqrt(3)*(2*rnd.Rndm() - 1);
	//double d = -TMath::log(1-rnd.Rndm());
	//double d = (2*rnd.Rndm()-1)*dim;//metodo di inversione
	
	if(x<0){
		d--;
		}
	if(x>0){
		d++;
		}
	
	//cout<<d<<" "<<x<<endl;//commentato se n grande
	
	h1.Fill(d);
	//h2.Fill(i, d);
	//h2.SetMarkerSize(3);
	gr.SetMarkerSize(3);
	gr.SetPoint(i, i, d);
	
}

h1.Draw();
//h2.Draw();

//gr.Draw("AP");

}