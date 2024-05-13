class Solution {
public:
    int rectCover(int number) {
                //递归，依然类似斐波那契数列
        // if(number==0)
        //     return 0;
        // if(number==1)
        //     return 1;
        // if (number ==2)
        //     return 2;
        // return rectCover(number - 1)+rectCover(number-2);
        if(number==0)
            return 0;
        if(number==1)
            return 1;
        if (number ==2)
            return 2;
        int x1=1,x2=2,ret=0;
        for(int i=2;i<number;i++){
            ret=x1+x2;
            x1=x2;
            x2=ret;
        }
        return ret;
    }
};