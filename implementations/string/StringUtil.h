// Description: String utility functions 

#define lowercase(s) transform((s).begin(), (s).end(), (s).begin(), ::tolower);  
#define uppercase(s) transform((s).begin(), (s).end(), (s).begin(), ::toupper);
