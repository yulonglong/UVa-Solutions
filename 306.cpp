// Steven Kester Yuwono - UVa 306

#include <bits/stdc++.h>
using namespace std;
#define MAX 201

int main() {
    int seq[MAX];
    int originalSeq[MAX];
    int repeatIndex[MAX];
    while(true) {
        int n;
        scanf("%d", &n);
        if (n == 0) break;
        memset(repeatIndex, 0, sizeof(repeatIndex));

        for (int i=0;i<n;i++) {
            scanf("%d", &seq[i]);
            originalSeq[i] = i;
        }

        // Get the repeat count for every position of the character
        for (int i=0;true;i++) {
            int currSeq[MAX];
            for (int j=0;j<n;j++) {
                currSeq[seq[j]-1] = originalSeq[j];
            }
            bool repeatIndexAllFilled = true;
            for (int j=0;j<n;j++) {
                originalSeq[j] = currSeq[j];
                if (repeatIndex[j] == 0) {
                    if (originalSeq[j] == j) repeatIndex[j] = i+1;
                    repeatIndexAllFilled = false;
                }
            }
            if (repeatIndexAllFilled) break;
        }

        while (true) {
            int k;
            scanf("%d", &k);
            if (k == 0) break;

            char theString[n];
            memset(theString, ' ', n);
            char temp; scanf("%c", &temp); // remove space
            int idx = 0;
            while (scanf("%c", &temp) == 1 && temp != '\n') {
                theString[idx++] = temp;
            }

            // Simulate
            char result[n];
            for (int i=0;i<n;i++) {
                int newIndex = i;
                for (int j=0;j< k%repeatIndex[i];j++) {
                    newIndex = seq[newIndex]-1;
                }
                result[newIndex] = theString[i];
            }

            // Print Result
            for (int i=0;i<n;i++) {
                printf("%c", result[i]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
