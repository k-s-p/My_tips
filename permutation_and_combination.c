//順列と組み合わせを配列に格納するコード
//n個の要素を並べるときの並べ方のパターンはnPn=n!通りある
//n個の要素からk個の要素を取り出すときの取り出し方のパターンはnCk = n!/k!(n-k)! 通りある
//参考：https://hatenaclang.blogspot.com/2011/09/blog-post_09.html

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//まず、配列のサイズを決めるために、P,Cの総数を計算する関数を作成
//numの階乗の総数を返す
unsigned long long int factorial(int num){
  int rs = 1;
  for(int i=num;i>0;i--) rs *= i;
  return rs;
}
//nPrの計算
//rep_flag==1なら重複順列の総数を返す
unsigned long long int ansP(int n, int r, int rep_flag){
  if(rep_flag == 1) return pow(n,r);
  else return factorial(n)/factorial(n-r);
}
//組み合わせの総数の計算方法
//rep_flag==1なら重複順列の総数を返す
unsigned long long int ansC(int n, int r, int rep_flag){
  if(rep_flag == 1) return factorial(n+r-1)/(factorial(r)*factorial(n-1));
  else return factorial(n)/(factorial(r)*factorial(n-r));
}

//重複順列
void rep_perm(int n, int r, int*** arrays){
  int arrayPointer = 0, *counter = (int*)malloc(sizeof(int)*r); //rのサイズ分の配列を確保
  for(int i=0;i<r;i++) counter[i] = 0; //counterの初期化
  while(counter[0] < n){
    for(int i=0;i<r;i++){
      (*arrays)[arrayPointer][i] = counter[i];
    }
    arrayPointer++;
    counter[r-1]++;
    for(int i=r-1;i>0;i--){
      if(counter[i] >= n){
        counter[i] = 0;
        counter[i-1]++;
      }
    }
  }
  free(counter);
}

//通常の順列
//ちょっと、意味わからない、、、
void perm(int n, int r, int *** arrays){
  int arrayPointer = 0, *idx = (int*)malloc(sizeof(int)*r), *counter = (int*)malloc(sizeof(int)*n);
  for(int i=0;i<r;i++) idx[i] = 0;
  while(idx[0]<n){
    for(int i=0;i<n;i++) counter[i] = i;
    for(int i=0;i<r;i++){
      int p=i+idx[i], t=counter[p];
      for(int j=p; j>i; j--) counter[j] = counter[j-1];
      counter[i] = t;
    }
    for(int i=0;i<r;i++) (*arrays)[arrayPointer][i] = counter[i];
    arrayPointer++;
    idx[r-1]++;
    for(int i=r-1;i>0;i--){
      if(idx[i] >= n-i){
        idx[i] = 0;
        idx[i-1]++;
      }
    }
  }
  free(idx);
  free(counter);
}

//重複組み合わせ
void rep_combi(int n, int r, int*** arrays){
  int arrayPointer = 0;
  int *counter = (int*)malloc(sizeof(int)*r);
  for(int i=0;i<r;i++) counter[i] = 0;
  while(1){
    for(int i=0;i<r;i++) (*arrays)[arrayPointer][i] = counter[i];
    arrayPointer++; counter[r-1]++;
    for(int i=r-1; i>0;i--){
      if(counter[i] >= n){
        counter[i] = 0;
        counter[i-1]++;
      }
    }
    if(counter[0] >= n) break;
    for(int i=0;i<r-1;i++){
      if(counter[i+1] < counter[i]) counter[i+1] = counter[i];
    }
  }
  free(counter);
}

//通常の組み合わせ
void combi(int n, int r, int*** arrays){
  int arrayPointer = 0, *counter = (int*)malloc(sizeof(int) * r);
  for(int i=0;i<r;i++) counter[i] = i;
  while(1){
    for(int i=0;i<r;i++) (*arrays)[arrayPointer][i] = counter[i];
    arrayPointer++; counter[r-1]++;
    for(int i=r-1;i>0;i--){
      if(counter[i] >= n-r+1+i){
        counter[i] = 0;
        counter[i-1]++;
      }
    }
    if(counter[0] >= n-r+1) break;
    for(int i=0;i<r-1;i++){
      if(counter[i+1]<=counter[i]) counter[i+1] = counter[i]+1;
    }
  }
  free(counter);
}

int main(){
  static const char ALPHA[] = "123456789";
  int num, s_num, rep_flag;
  scanf("%d %d %d", &num, &s_num, &rep_flag);
  printf("n=%d,r=%d,重複:%d\n", num, s_num, rep_flag);
  int fact = factorial(num);
  int ansp = ansP(num, s_num, rep_flag);
  int ansc = ansC(num, s_num, rep_flag);
  printf("nの階乗：%d\n", fact);
  printf("nPrの計算結果：%d\n", ansp);
  printf("nCrの計算結果：%d\n", ansc);

  //配列の準備
  int** p_arrays = (int**)malloc(sizeof(int*)*(ansp));
  for (unsigned long long int i = 0; i<ansp; i++) p_arrays[i] = (int*)calloc(s_num, sizeof(int));
  int** c_arrays = (int**)malloc(sizeof(int*)*(ansc));
  for (unsigned long long int i = 0; i<ansc; i++) c_arrays[i] = (int*)calloc(s_num, sizeof(int));

  //配列に順列を格納
  if(rep_flag == 1) rep_perm(num, s_num, &p_arrays);
  else perm(num, s_num, &p_arrays);
  if(rep_flag == 1) rep_combi(num, s_num, &c_arrays);
  else combi(num, s_num, &c_arrays);

  //表示
  if(rep_flag == 1){
  printf("重複順列の結果\n");
    for(unsigned long long int i=0;i<ansp;i++){
      printf("%03lld：", i);
      for(int j=0;j<s_num;j++){ printf(" %c ", ALPHA[p_arrays[i][j]]); }
      printf("\n");
    }
  }else {
    printf("順列の結果\n");
      for(unsigned long long int i=0;i<ansp;i++){
        printf("%03lld：", i);
        for(int j=0;j<s_num;j++){ printf(" %c ", ALPHA[p_arrays[i][j]]); }
        printf("\n");
      }
  }
  if(rep_flag == 1){
  printf("重複組み合わせの結果\n");
    for(unsigned long long int i=0;i<ansc;i++){
      printf("%03lld：", i);
      for(int j=0;j<s_num;j++){ printf(" %c ", ALPHA[c_arrays[i][j]]); }
      printf("\n");
    }
  }else {
    printf("組み合わせの結果\n");
      for(unsigned long long int i=0;i<ansc;i++){
        printf("%03lld：", i);
        for(int j=0;j<s_num;j++){ printf(" %c ", ALPHA[c_arrays[i][j]]); }
        printf("\n");
      }
  }

  //配列の解放
  for(long long int i=0;i<ansp;i++){
    free(p_arrays[i]);
  }
  free(p_arrays);
  for(long long int i=0;i<ansc;i++){
    free(c_arrays[i]);
  }
  free(c_arrays);
  /*free(*p_arrays)と書いて、ずっとコアダンプしてた
  この二次元配列を動的保持するやり方はよく理解する必要がある、、、
  参考：https://tondol.hatenablog.jp/entry/20090713/1247426321
  */

  return 0;
}
