class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n1 = a.size();
        int n2 = b.size();

        int n = n1 + n2;

        int ind1 = n / 2 - 1;
        int ind2 = n / 2;

        int i = 0, j = 0;
        int cnt = 0;

        int ind1el = -1;
        int ind2el = -1;

        while (i < n1 && j < n2) {

            if (a[i] < b[j]) {
                if (cnt == ind1)
                    ind1el = a[i];

                if (cnt == ind2)
                    ind2el = a[i];

                i++;
            }
            else {
                if (cnt == ind1)
                    ind1el = b[j];

                if (cnt == ind2)
                    ind2el = b[j];

                j++;   // Missing in your code
            }

            cnt++;
        }

        // Remaining elements of a
        while (i < n1) {
            if (cnt == ind1)
                ind1el = a[i];

            if (cnt == ind2)
                ind2el = a[i];

            i++;       // You had j++
            cnt++;
        }

        // Remaining elements of b
        while (j < n2) {
            if (cnt == ind1)
                ind1el = b[j];

            if (cnt == ind2)
                ind2el = b[j];

            j++;
            cnt++;
        }

        // Odd length
        if (n % 2 == 1)
            return ind2el;

        // Even length
        return (ind1el + ind2el) / 2.0;
    }
};