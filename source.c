
/* スパコン数の計算 */
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#define SUPERCONMAX 21561984
#define PRIMEMAX 10529
#define PRIMENUM 4643

/* クイックソート関数の比較関数 */
int compare(const int *a, const int *b)
{
    return *a - *b;
}

int main() {
	
	/* 変数の宣言 */
	int n;
	int Prime[PRIMENUM];		/* 0..4643 ( ≒ √21561984 ) */
	int c=0, lim;
	int ii, jj;
	int flag[12] = {1,1,1,1,1,1,1,1,1,1,1,0};
	static int sortarray[50000];
	int cnt = 0;

	/* nの読み込み */
	scanf("%d",&n);

	/* 素数リストの作成 */
	Prime[c++]=0;
	for (ii=2;ii<=PRIMEMAX;ii++){
		lim = (int)sqrt(ii);
		for (jj=lim;jj>1;jj--){
			if ( !(ii%jj) ) break;
		}
		if (jj==1){
			Prime[c++] = ii;
		}
	}

	do {
		/* 素数リストを１つ進める */
		for ( ii=11; ii >= 0; ii--){						
			if ( ++flag[ii] != c )
				break;
			else {
				/* 素数リストの上限にきたら項の繰り上げ */
				for ( jj=ii; jj<12; jj++) flag[jj]=flag[ii-1]+1;
			}
		}
		/* 5の12乗は明らかに上限値を超えている */
		if (flag[0]==3) break;								
		jj = 1;
		/* SuperCon数を求める */
		for ( ii=0; ii < 12; ii++ ) jj *= Prime[flag[ii]];	
		/* 上限値を超えていたら項の繰上げ */
		if ( SUPERCONMAX < jj ) {
			for ( ii=10; ii>=0; ii--) {
				if (flag[ii]==flag[11]) flag[ii]=c-1;
			}
			flag[11]=c-1;
		/* n より大きいなら配列に格納 */
		} else if ( n < jj ) {
			sortarray[cnt++]=jj;
		}
	} while ( 1 );

	/* クイックソート関数 */
	qsort(sortarray, cnt, sizeof(int), (int (*)(const void*, const void*))compare );
	for ( ii = 0 ; ii < 40000; ii++ ){
		printf("%d¥n",sortarray[ii]);
	getchar();
	}
	printf("%d¥n",sortarray[2003]);

	getchar();
	getchar();

}
