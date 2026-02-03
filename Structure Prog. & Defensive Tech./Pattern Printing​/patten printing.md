<img src="./qy1ymdth.png"
style="width:0.44792in;height:1.125in" /><img src="./1r55njk3.png"
style="width:0.39583in;height:1.1875in" />

//Question 1

\#include \<stdio.h\>

int main(){

> for(int i = 1;i\<=3;i++){ for(int j=1;j\<=i;j++){
>
> printf("\*"); }
>
> printf("\n"); }
>
> for(int i =2;i\>=1;i--){ for(int j=1;j\<=i;j++){
>
> printf("\*");
>
> } printf("\n");
>
> }

}

//Question 2

\#include \<stdio.h\>

<img src="./z0ou2ama.png"
style="width:0.61458in;height:1.17708in" />

int main(){

> for(int i=1;i\<=3;i++){ for(int j=1;j\<=i;j++){
>
> printf("%d",j); }
>
> printf("\n");
>
> }

for(int i=2;i\>=1;i--){ for(int j=1;j\<=i;j++){

> printf("%d",j); }

printf("\n"); }

}

//Question 3

\#include \<stdio.h\>

int main(){

> int num = 1;
>
> for(int i=1;i\<=3;i++){ for(int j=1;j\<=i;j++){

<img src="./xpsq40oj.png" style="width:0.63542in;height:1.25in" />

> printf("%d",num++); }
>
> printf("\n");
>
> }

for(int i=2;i\>=1;i--){ for(int j=1;j\<=i;j++){

> printf("%d",num++); }

printf("\n"); }

}

//Question 4

\#include \<stdio.h\>

int main() {

> // Upper part
>
> for(int i = 1; i \<= 3; i++) { for(int j = 0; j \< i; j++) {
>
> printf("%c ", 'A' + j); }
>
> printf("\n"); }
>
> // Lower part
>
> for(int i = 2; i \>= 1; i--) { for(int j = 0; j \< i; j++) {
>
> printf("%c ", 'A' + j);

<img src="./hthqlhj0.png"
style="width:0.60417in;height:1.22917in" />

> } printf("\n");
>
> }

return 0; }

//Question 5

\#include \<stdio.h\>

int main() {

> char ch = 'a';
>
> // Upper part
>
> for(int i = 1; i \<= 3; i++) { for(int j = 1; j \<= i; j++) {
>
> printf("%c ", ch); ch++;
>
> } printf("\n");
>
> }
>
> // Lower part
>
> for(int i = 2; i \>= 1; i--) { for(int j = 1; j \<= i; j++) {
>
> printf("%c ", ch); ch++;
>
> } printf("\n");
>
> }

return 0; }

<img src="./m4od1gom.png"
style="width:1.02083in;height:1.27083in" />

//Question 6

\#include \<stdio.h\>

int main() { int n = 3;

> // Upper part
>
> for(int i = n; i \>= 1; i--) {
>
> // Spaces
>
> for(int j = 0; j \< n - i; j++) printf(" ");
>
> // Symbols
>
> for(int k = 1; k \<= (2\*i - 1); k++) printf("\* ");
>
> printf("\n"); }
>
> // Lower part
>
> for(int i = 2; i \<= n; i++) {
>
> // Spaces
>
> for(int j = 0; j \< n - i; j++) printf(" ");
>
> // Symbols
>
> for(int k = 1; k \<= (2\*i - 1); k++) printf("\* ");
>
> printf("\n"); }

return 0; }

<img src="./ghcibycb.png"
style="width:1.30208in;height:1.20833in" />

//Question 7

\#include \<stdio.h\>

int main() {

> int num = 1;
>
> // Row 1 → 5 numbers for(int i = 0; i \< 5; i++)
>
> printf("%-3d", num++); printf("\n");
>
> // Row 2 → spaces + 3 numbers printf(" ");
>
> for(int i = 0; i \< 3; i++) printf("%-3d", num++);
>
> printf("\n");
>
> // Row 3 → spaces + 1 number printf(" ");
>
> printf("%-3d\n", num++);
>
> // Row 4 → spaces + 3 numbers printf(" ");
>
> for(int i = 0; i \< 3; i++) printf("%-3d", num++);
>
> printf("\n");
>
> // Row 5 → 5 numbers for(int i = 0; i \< 5; i++)
>
> printf("%-3d", num++); printf("\n");

return 0; }

<img src="./4341thdq.png" style="width:1.08333in;height:1.25in" />

//Question 8

\#include \<stdio.h\>

int main() { char ch = 'a';

> // Row 1 → 5 letters for(int i = 0; i \< 5; i++)
>
> printf("%c ", ch++); printf("\n");
>
> // Row 2 → spaces + 3 letters printf(" ");
>
> for(int i = 0; i \< 3; i++) printf("%c ", ch++);
>
> printf("\n");
>
> // Row 3 → spaces + 1 letter printf(" ");
>
> printf("%c\n", ch++);
>
> // Row 4 → spaces + 3 letters printf(" ");
>
> for(int i = 0; i \< 3; i++) printf("%c ", ch++);
>
> printf("\n");
>
> // Row 5 → 5 letters for(int i = 0; i \< 5; i++)
>
> printf("%c ", ch++); printf("\n");

return 0; }

//Question 9

<img src="./vs1k43ik.png"
style="width:1.0625in;height:1.13542in" /><img src="./2k5i4tyi.png"
style="width:0.94792in;height:1.29167in" />

\#include \<stdio.h\>

int main() { int n = 5;

> for(int i = 1; i \<= n; i++) { for(int j = 1; j \<= n; j++) {
>
> if(j \<= i && j == 1 \|\| j \<= i && j == i \|\|
>
> j \>= n-i+1 && j == n \|\| j \>= n-i+1 && j == n-i+1) printf("\* ");
>
> else if(i == 3) printf("\* ");
>
> else
>
> printf(" "); }
>
> printf("\n"); }

return 0; }

//Question 10

\#include \<stdio.h\>

int main() {

> int n = 5; char ch = 'a';

<img src="./z2ckiwko.png"
style="width:1.36458in;height:1.64583in" />

> for(int i = 1; i \<= n; i++) {
>
> for(int j = 1; j \<= n; j++) {
>
> if(j \<= i && (j == 1 \|\| j == i) \|\|
>
> j \>= n-i+1 && (j == n \|\| j == n-i+1) \|\| i == 3)
>
> {
>
> printf("%c ", ch++); }
>
> else {
>
> printf(" "); }
>
> } printf("\n");
>
> }

return 0; }

//Question 11

\#include \<stdio.h\>

int main() { int i, j;

> int n = 7; // size of the pattern
>
> for (i = 1; i \<= n; i++) { for (j = 1; j \<= n; j++) {
>
> if (i == 1 \|\| i == n \|\| j == 1 \|\| j == n) { printf("\* ");

<img src="./ksh4545o.png"
style="width:1.375in;height:1.01042in" />

> } else { printf(" ");
>
> }
>
> } printf("\n");
>
> }

return 0; }

//Question 12

\#include \<stdio.h\>

int main() { int i, j;

> int n = 4; // square size int num = 1;
>
> for (i = 1; i \<= n; i++) { for (j = 1; j \<= n; j++) {
>
> if (i == 1 \|\| i == n \|\| j == 1 \|\| j == n) { printf("%-4d", num);
> // fixed width = 4 num++;
>
> } else {
>
> printf(" "); // same width as number }
>
> } printf("\n");
>
> }

return 0; }

<img src="./jy5qn34e.png"
style="width:1.07292in;height:0.98958in" /><img src="./e1ol0fup.png"
style="width:1.11458in;height:1.16667in" />

//Question 13

\#include \<stdio.h\>

int main() { int i, j; int n = 4;

> char ch = 'A';
>
> for (i = 1; i \<= n; i++) { for (j = 1; j \<= n; j++) {
>
> if (i == 1 \|\| i == n \|\| j == 1 \|\| j == n) { printf("%-3c", ch);
> // fixed cell width = 3 ch++;
>
> } else {
>
> printf(" "); // SAME width as above }
>
> } printf("\n");
>
> }

return 0; }

//Question 14

\#include \<stdio.h\>

int main() { int i, j;

<img src="./uqwwqfor.png" style="width:1.34375in;height:1.25in" />

> int n = 5; // height of triangle
>
> for (i = 1; i \<= n; i++) { for (j = 1; j \<= i; j++) {
>
> if (j == 1 \|\| j == i \|\| i == n) { printf("\* ");
>
> } else { printf(" ");
>
> }
>
> } printf("\n");
>
> }

return 0; }

//Question 15

\#include \<stdio.h\>

int main() { int i, j;

> int n = 5; // height of triangle char ch = 'a';
>
> for (i = 1; i \<= n; i++) { for (j = 1; j \<= i; j++) {
>
> if (j == 1 \|\| j == i \|\| i == n) { printf("%-3c", ch); // fixed
> width ch++;
>
> } else {
>
> printf(" "); // same width for space }

<img src="./iyukdbs3.png"
style="width:0.59375in;height:1.125in" />

> } printf("\n");
>
> }

return 0; }

//Question 16

\#include \<stdio.h\>

int main() { int i, j; int n = 5;

> for (i = 1; i \<= n; i++) {
>
> /\* spaces for right alignment \*/ for (j = i; j \< n; j++) {
>
> printf(" "); }
>
> /\* triangle \*/
>
> for (j = 1; j \<= i; j++) {
>
> if (j == 1 \|\| j == i \|\| i == n) { printf("\*");
>
> } else { printf(" ");
>
> } }
>
> printf("\n"); }

return 0; }
