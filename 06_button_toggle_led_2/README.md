# 8051 Project - Buzzer Toggle LED 2

這是一個基於 STC89C52RC（8051）微控制器的示例專案，展示如何使用外部中斷 INT1 控制 LED 的亮滅。

## 硬體要求

* STC89C52RC 微控制器 x1
* 按鍵開關 x1
* 220Ω 電阻 ×1
* LED x1

## 軟體依賴

* VSCode
* EIDE
* Keil C51 Toolchain

## 電路圖

![img](./img/image.png)

## 構建和編譯

1. 使用 VSCode 開啟專案資料夾
2. 確認 EIDE 已設定 Keil C51 Toolchain
3. 執行 Build
4. 產生 HEX 檔
5. 使用 stcflash 燒錄至微控制器

## 使用方法

將程式燒錄至 STC89C52RC 後，每按下一次按鍵，LED 將切換一次亮滅。

## 功能介紹

* 外部中斷

  使用 INT1 偵測按鍵輸入，採用下降沿觸發方式

* 中斷處理函式

  ISR 僅負責設定事件旗標，不執行延遲或其他耗時工作，以降低中斷執行時間。

* 按鍵消抖

  主程式收到事件後，進行約 20 ms 軟體消抖，再次確認按鍵狀態，避免按鍵彈跳造成誤觸發

* LED 控制

  確認按鍵有效後，切換 LED 的輸出狀態，實現按一下切換一次亮滅（Toggle）