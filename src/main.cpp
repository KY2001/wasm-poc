#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <complex>
#include <Eigen/Dense>


int main(){
    // ログの出力
    std::cout << "プログラムの開始！" << std::endl
        << "このWasmバイナリでは、行列演算ライブラリのEigenを用いて行列計算を行います。" << std::endl
        << "具体的なパラメータなどは `src/main.cpp` をご覧ください。" << std::endl
        << std::endl;
    // 開始時間の測定
    auto start_time = clock();

    // Eigenの利用
    int n = 9;
    int size = (1 << n);
    int rep = 10;

    // ランダム行列の生成
    Eigen::Matrix<std::complex<double>, Eigen::Dynamic, Eigen::Dynamic> x = Eigen::MatrixXcd::Random(size, size);
    Eigen::Matrix<std::complex<double>, Eigen::Dynamic, Eigen::Dynamic> y = Eigen::MatrixXcd::Random(size, size);

    // size×size行列の行列積をrep回繰り返す
    for (int _ = 0; _ < rep; _++){
        x *= y;
    }

    std::cout << "プログラムが終了しました！\n" 
        << "処理に要した時間は、" << std::fixed << std::setprecision(6)
        << (double)(clock() - start_time) / CLOCKS_PER_SEC << " 秒でした。" 
        << std::endl;
}
