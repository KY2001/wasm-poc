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
1. When compiled by GCC in the native environment: 2.73 sec.
```
プログラムの開始！
プログラムが終了しました！
処理に要した時間は、0.718791 秒でした。
```

2. When Wasm binary is run on the chrome browser: 5.91 sec
```
プログラムの開始！
プログラムが終了しました！
処理に要した時間は、1.199000 秒でした。
```

<strong>-> Even on the browser, the performance is almost equivalent to that of the native environment.</strong><br>
(In both cases, the O3 optimization is enabled.)


## How to execute wasm binary
1. Clone this project.
2. Move to the `/public` directory.
3. Install Python and run the following command from a terminal.
```
python -m http.server 8080
```
4. Open `http://localhost:8080/main.html` from your browser.

## How to build.
1. Install and activate Emscripten according to the [official documentation](https://emscripten.org/docs/getting_started/downloads.html).
2. Clone this prject.
```
git clone https://github.com/KY2001/Wasm-PoC
```
3. Move to the `/build` directory.
4. Run the following command from a terminal.
```
emccmake cmake ..
make
```
5. The Wasm binary (main.wasm) and corresponding JavaScript file (main.js) are generated in `/public` directory.
