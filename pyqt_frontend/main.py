import sys
sys.path.append(r"C:\Users\s.nejad\Desktop\cmake_project\financial_analytics_tool\build\Release\finanalytics.cp311-win_amd64.pyd")

from PyQt5.QtWidgets import QApplication, QMainWindow, QPushButton, QLineEdit, QLabel, QVBoxLayout, QWidget
import finanalytics  # C++ backend module



class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Financial Analytics Tool")

        self.amount_input = QLineEdit(self)
        self.amount_input.setPlaceholderText("Enter amount")
        self.amount_input.setGeometry(50, 50, 200, 30)

        self.result_label = QLabel("VAT Result:", self)
        self.result_label.setGeometry(50, 100, 300, 30)

        self.calc_button = QPushButton("Calculate VAT", self)
        self.calc_button.setGeometry(50, 150, 200, 30)
        self.calc_button.clicked.connect(self.calculate_vat)

        layout = QVBoxLayout(self)

        layout.addWidget(self.amount_input)
        layout.addWidget(self.result_label)
        layout.addWidget(self.calc_button)

        widget = QWidget()
        widget.setLayout(layout)

        self.setCentralWidget(widget)

    def calculate_vat(self):
        amount = float(self.amount_input.text())
        vat = finanalytics.calculateVAT(amount, 0.09)  # 9% VAT
        self.result_label.setText(f"VAT Result: {vat:.2f}")

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())
