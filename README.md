# Blackjack Game 🎲🃏  

This is a **C++ implementation of the classic casino game Blackjack**. The game allows users to play against a computer dealer with a virtual betting system. It also includes file handling to save and retrieve user account balances.  

## 📁 Repository Structure  
```
Blackjack-Card-Game/  
│── src/  
│   ├── blackjack.cpp      # Main game code  
│── docs/  
│   ├── Project_Report.docx  # Original project report from Grade 12  
│── README.md              # Project description and setup guide  
│── LICENSE                # Open-source license  
```

## 🚀 Features  

- 🎮 Single-player Blackjack against a computer dealer.  
- 💰 Virtual betting system with account balance tracking.  
- 🎨 Simple text-based interface using C++.  
- 📂 Binary file handling to store and retrieve user data.  

## 🛠️ How to Run  

### **Requirements:**  
- A **C++ compiler** (e.g., **g++**, **MinGW**, **Turbo C++**).  
- A **terminal/command prompt**.  

### **Compilation & Execution**  

#### **Using g++ (Recommended)**  
1. Open a terminal and navigate to the `src/` directory.  
2. Compile the program using:  

   ```sh
   g++ blackjack.cpp -o blackjack
   ```  

3. Run the executable:  

   ```sh
   ./blackjack
   ```  

#### **Using Turbo C++ (For Older Setups)**  
1. Open **Turbo C++**.  
2. Load the `blackjack.cpp` file.  
3. Compile and run from the Turbo C++ IDE.  

## ⚠️ Known Issues & Security Considerations

- **🔑 Passwords are stored in plain text**: The game saves usernames and passwords in a binary file (`BJUSER.dat`) **without encryption**, making it insecure. A future improvement would be to **hash passwords** before storing them.
- **❌ No password recovery option**: If a user forgets their password, there's no way to reset it.
- **🔓 User data can be modified manually**: Since account balances are stored locally in `BJUSER.dat`, someone with access to the file can **manually edit** their balance. Future improvements could include **encryption** or **checksum validation**.
- **📂 Missing file issues**: If `BJUSER.dat` is deleted or corrupted, the game may crash. A fix could be to add **automatic file creation** when missing.

## 📜 License  
This project is licensed under the **MIT License**. See the `LICENSE` file for details.  

## 📄 Project Documentation  
The original **Class 12 board submission document** is included in the `docs/` folder.  

## 🎯 Future Improvements  
- 🖥️ Add a **Graphical User Interface (GUI)** for a better user experience.  
- 👥 Implement **multiplayer mode**.  
- 🔄 Improve **randomness** in shuffling and card dealing.
- **Implement password hashing (e.g., SHA-256)**
- **Add password reset functionality**
- **Encrypt user data to prevent manual tampering** 

## 📬 Contact  
If you have any questions or suggestions, feel free to open an **issue** or **pull request** in this repository!  

Enjoy playing Blackjack! 🃏✨  
