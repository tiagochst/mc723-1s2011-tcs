int prime(int n) {
   int i = 2;
   while ( (i < n) && (n % i) ) {
     i++;
   }
   return i;
}

int main (void) {
   int a,b,c;

   a = 719;

   b = prime(a);

   if (a == b) {
     c = 1;
//      printf("\nPrimo\n");
   } else {
     c = 0;
//      printf("\nNao Primo\n");
   }

   return 0;
}
