# 第二十二組 資工1A 陳宥芯 張峰榮 汪裕軒 

## Maze Escape Game（迷宮逃脫遊戲）
 
這是一個使用 C++ 製作的終端機迷宮逃脫小遊戲。
玩家需操作主角 `@`，在時間限制內從迷宮中找到出口 `E`。



## 遊戲玩法

時間限制根據難度從 90 秒 ~ 30 秒不等
迷宮為純文字檔，每關不同（支援最多 7 張）
玩家初始位置固定為 `(1,1)`，用 `WASD` 鍵移動
每次成功通關都會記錄花費時間於 `record.txt`



## 操作方式

 `W`  上移 
 `A`  左移
 `S`  下移 
 `D`  右移
 `Q`  中途退出 



## 檔案說明    

 main.cpp        主選單、說明、排行榜邏輯      
 Game.h/cpp      管理遊戲流程與時間限制        
 Maze.h/cpp      載入並顯示迷宮地圖             
 Player.h/cpp    控制玩家位置與移動             
 maze1.txt ~ 7   地圖檔（需放入同資料夾）        
 record.txt      成功逃脫的記錄（自動生成） 

 
## 運行截圖

開始執行的主選單
![image](https://github.com/user-attachments/assets/48887730-3abe-4125-b99e-bca571abdfd7)


輸入3可閱讀遊戲說明
![image](https://github.com/user-attachments/assets/635fa5a0-6ca9-4a82-9a32-e4cadaee8511)


回到主畫面後選擇開始遊戲
輸入1開始遊戲可選擇難度或隨機
![image](https://github.com/user-attachments/assets/f7d92d8e-6877-46a3-b4e3-50027f7888a9)


選擇最簡單的難度1
最一開始在(11)，現實90秒
![image](https://github.com/user-attachments/assets/d8df3ab9-424e-4638-9e3d-a3c5e2e966a6)


剩餘時間會顯示，牆壁(#)不可穿越

E為終點，即會停止倒數
輸入4到排行榜
可看到之前所有遊戲所運用的時間

## 分工
陳宥芯  主題發想與確認、架構設計、程式開發、
        測試與除錯、主要簡報製作、簡報與文件整理、報告main及Game
張峰榮  迷宮地圖製作、擴充功能建議、測試執行、報告Maze
汪裕軒  簡報製作、報告Player


## PPT連結
https://www.canva.com/design/DAGlcjZkNXw/Ucg-C_xOXkdGOIdNtbYNow/edit?utm_content=DAGlcjZkNXw&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton
