# Chương 2: Cấu trúc máy tính
## 1  Các thành phần của hệ điều hành
- Quản lý tiến trình (Task Manager)
    + Khống chế tắt nghẽn
    + Keyword: tiến trình
- Quản lý bộ nhớ chính (Resource Monitor)
    + Keyword: vùng nhớ
- Quản lý file (File explorer)
    + Keyword: thư mục, file
    + Sao lưu và hồi phục dữ liệu
- Quản lý hệ thống I/O (Device Manager)
    + Cơ chế: buffering, caching, spooling
    + Cung cấp giao diện điều khiển thiết bị
    + Bộ điều khiển các thiết bị phần cứng
- Quản lý hệ thống lưu trữ thứ cấp (Disk Manager)
    + Keyword: không gian lưu trữ
    + `free space management`: Quản lý không gian trống trên đĩa
    + `storage allocation`: cấp phát không gian lưu trữ
    + `disk scheduling`: Định thời hoạt động cho đĩa    
- Hệ thống bảo vệ (Window Security, Window Defender Security Center)
    + Keyword:nghe nó an ninh, đăng nhập đăng xuất
- Hệ thống thông dịch lệnh (Cmd)
    + Là giao diện chủ yếu giữa người dùng và OS
## 2 Các dịch vụ hệ điều hành cung cấp (Computer Management -> services)
- Thực thi chương trình
- Thực hiện các thao tác I/O theo yêu cầu của chương trình
- Các thao tác trên hệ thống file
- Trao đổi thông tin giữa các tiến trình qua hai cách:
  + `Shared memory`: chia sẻ bộ nhớ
  + `Message Passing`: chuyền thông điệp
- Phát hiện lỗi
  + Trong CPU, bộ nhớ, trên thiết bị I/O
  + Do chương trình: chia cho 0, truy cập đến địa chỉ bộ nhớ không cho phép
- `Resource allocation`: cấp phát tài nguyên
  + OS có các `routine` tương ứng
- `Accounting`: kế toán
- `Protection` và `Security`
  - Giao diện
    + Command-Line (CLI)
    + GUI 
    + Touch-screen

## 3 Lời gọi hệ thống
- Dùng để giao tiếp giữa tiến trình và hệ điều hành hay là cung cấp giao diện giữa tiến trình và hệ điều hành bằng cách gọi các dịch vụ mà OS cung cấp
- Thông thường được viết bằng ngôn ngữ bậc cao (C hoặc C++) và hầu hết được truy cập thông qua các `API` (Application Programing Interface)
    + Win32 API (cho window)
    + POSIX API (cho UNIX, Linux, MacOS)
    + Java API (cho các máy ảo Java `JVM`)
- Có 3 phương pháp truyền tham số khi sử dụng system call:
    + Qua register
    + Qua một vùng nhớ, địa chỉ vùng nhớ được gửi đến OS thông qua reg
    + Qua stack

## 4 Các chương trình hệ thống
- Người dùng chủ yếu làm việc thông qua system program (không làm việc `trực tiếp` với system call)

## 5 Cấu trúc hệ thống
- Có 5 cấu trúc:
    + Cấu trúc Monolithic-Original UNIX
        - UNIX giới hạn về phần cứng nên Original UNIX cũng có cấu trúc giới hạn
        - UNIX gồm 2 phần: Nhân và system program
    + Cấu trúc Layered Approach 
        - Lớp dưới cùng (bên trong): hardware
        - CPU scheduling
        - Memory Management
        - Process Mângement
        - I/O Buffer
        - Lớp trên cùng (bên ngoài): user program
        - Lưu ý, lớp trên chỉ phụ thuộc vào lớp dưới
        - Một lớp chỉ có thể gọi hàm của lớp dưới và các hàm của nó chỉ được gọi bởi lớp trên
    + Cấu trúc Microkernels - cấu trúc vi nhân
        - Ánh xạ 
    + Cấu trúc Modules
        - Hướng đối tượng
        - Trao đổi thông qua các `interfaces`
        - Mỗi module là 1 phần của nhân
    + Cấu trúc Hybrid Systems   
        - Kết hợp từ nhiều cái trên nên giải quyết được nhiều thứ và đổi lại khó cài đặt
        - Nhân window là theo cấu trúc liền khối

