//calculates how many roots each proc gets
int * calcLaunchPar(int numProc, int V) {
	int * par = (int *) malloc(sizeof(int) * 2);
	
	if (numProc > V) {
		numProc = V;
	}
	
	int d = V/numProc;
	int r = V%numProc;
	
	if (r == 0) {
		par[0] = d;
		par[1] = d;
	} else {
		par[0] = d;
		par[1] = d + r;
	}

	return par;
}

//validates proc ID
bool validNumProc(int V, int numProc) {
	return (numProc > 0 && numProc <= V);
}

//Prints metric closure
void print(int * G, int V) {
	printf("Metric Closure:\n");
	 for(int i = 0; i < V; i++, printf("\n")) {
		  for(int j = 0; j < V; j++) {
		     int out = G[i * V + j];
		     if(out  == INF)
		        printf("%3s " , "INF");
		     else
		        printf("%3d " , out );
		  }
	 }
	 printf("\n");
}

//Print one star
void printOnestar(int * onestar, int numGroups, int V) {
	for(int i = 0; i < V; i++) {
		 printf("Root%d:  ", i);
		 for(int j = 0; j < numGroups; j++)
			  printf("%3d  ", onestar[i * numGroups + j]);
		 printf("\n");
	}
}
	
