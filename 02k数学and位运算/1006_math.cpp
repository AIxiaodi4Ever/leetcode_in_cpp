class Solution {
public:
    int clumsy(int N) {
        switch(N) {
            case 1:
                return 1;
            case 2:
                return 2;
            case 3:
                return 6;
            case 4:
                return 7;
            default:
                break;
        }

        switch(N % 4) {
            case 0:
                return N + 1;
            case 1:
            case 2:
                return N + 2;
            case 3:
                return N - 1;
            default:
                break;
        }

        return 0;
    }
};