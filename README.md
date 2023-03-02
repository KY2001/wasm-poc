# Wasm-PoC
## What is this?
Generate Wasm binary and compare performance with native environment.<br>
The program itself is very simple, just use [Eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page) to obtain the matrix product.<br>
`src/main.cpp`
```
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <complex>
#include <Eigen/Dense>
#include <boost/array.hpp>
// #include <emscripten.h>


int main(){
    std::cout << "プログラムの開始！" << std::endl;
    // 開始時間の測定
    auto start_time = clock();

    // Eigenの利用
    int n = 9;
    int size = (1 << n);
    int rep = 1;
    // 単位行列
    Eigen::Matrix<std::complex<double>, Eigen::Dynamic, Eigen::Dynamic> x = Eigen::MatrixXcd::Identity(size, size);

    // size×size行列の行列積をrep回繰り返す
    for (int _ = 0; _ < rep; _++){
        x *= Eigen::MatrixXcd::Random(size, size);
    }

    std::cout << "プログラムが終了しました！\n" 
        << "処理に要した時間は、" << std::fixed << std::setprecision(6)
        << (double)(clock() - start_time) / CLOCKS_PER_SEC << " 秒でした。" 
        << std::endl;
}
```

## performance comparison
1. When compiled by GCC in the native environment



## How to build.
1. Install and activate Emscripten by following [here](https://emscripten.org/docs/getting_started/downloads.html).
2. Clone this prject.
```
git clone https://github.com/KY2001/Wasm-PoC
```
3. 
