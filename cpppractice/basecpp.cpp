#include <iostream>
using  namespace std;

// 初始化二维数组，通过用户输入填充数组元素
void initializeArray(int**a,int rows,int cols){
    cout<<"请输入数组元素:"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
           cin>>a[i][j];
        }
    }
}

// 打印二维数组的所有元素
void printArray(int**a,int rows,int cols){
    cout<<"数组元素为:"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

// 计算二维数组中所有元素的和
int sumArray(int**a,int rows,int cols){
    int sum=0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            sum+=a[i][j];   
        }
    }
    return sum;
}

// 查找二维数组中的最大元素及其位置
void findMax(int**a,int rows,int cols){
    int max=a[0][0];
    int maxRow=0,maxCol=0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(a[i][j]>max){
                max=a[i][j];
                maxRow=i;
                maxCol=j;
            }
        }
    }
    cout<<"最大元素为:"<<max<<",其位置为("<<maxRow<<","<<maxCol<<")"<<endl;
}

// 主函数，程序入口
int main(){
    const int rows = 3;
    const int cols = 6;
    int** a =new int*[rows];
    for(int i=0;i<rows;i++){             //分配空间
        a[i] = new int[cols];
    }
    initializeArray(a,rows,cols);
    printArray(a,rows,cols);
    int sum=sumArray(a,rows,cols);
    cout<<"数组元素之和为:"<<sum<<endl;
    findMax(a,rows,cols);

    for(int i=0;i<rows;i++){             //释放内存
        delete[] a[i];

    }
    delete[] a;
    return 0;
}