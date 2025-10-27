# Hệ điều hành
- Từ chương 3 đến chương 6 sẽ học về quản lý tiến trình
-  Chương 5 khó nhất nhớ chú ý.
- Chương 7 và 8 sẽ học quản lý bộ nhớ chính (RAM)

- Cấu trúc của 1 lệnh linux thường sẽ có 3 phần:
  + `command`: tên lệnh (chỉ ra `việc` user muốn thực hiện)
  + `params`: các tham số được sử dụng bởi lệnh (còn được gọi là command-line params)
  + `-options`: chỉ ra `cách thức` mà lệnh được thực thi

| Command       | Chức năng                         |
|---------------------|-----------------------------------|
| ls        | liệt kê thư mục     |
| cd        | Chuyển đến thư mục            |
| pwd       | in ra đường dẫn thư mục mình đang ở        |
| which     | in ra đường dẫn của lệnh mình chạy        |
| mkdir     | Tạo thư mục         |
| touch     | Tạo file rỗng |
| cp        | Copy thư mục hoặc sang chỗ khác                    |
| mv        | Move thư mục hoặc file sang chỗ khác                |
| rm        | Xóa file               |                  |
| echo      | Đọc chuỗi, thêm chuỗi, ghi đè chuỗi vào file      |
| cat       | Hiển thị nội dung file ra màn hình       |
| chmod     | Cấp quyền sử dụng thư mục |
| useradd   | tạo user      |
| groupadd  | tạo group |
| chown     | đổi chủ sở hữu của tệp hoặc thư mục |
| ps        | xem id của tiến trình          |
| kill      | Để dừng tiến trình        |
| >         | Đầu ra hướng tới.... |
| >>        | Nối vào nội dung của... |
| <         | Đầu vào là ở đây... |
| 2>        | Đầu ra báo lỗi sẽ hướng vào... |
| 2>>       | Đầu ra sẽ lỗi và ghi thêm vào... |
| set       | Dùng để gán tham số               |
| $@        | Danh sách tham số (không theo IFS) |
| $*        | Danh sách tham số (theo IFS)  |
| []        | Các tác dụng (nhớ có khoảng trắng giữa lệnh [] và biểu thức)      |
| -n


![alt text](<OS_image/image copy.png>)
![alt text](<OS_image/image copy.png>)
![alt text](<OS_image/image copy 3.png>)

sudo service ssh start
- `` Lệnh trong đây sẽ được thực thi trước và kết quả của lệnh đó sẽ thay thế đầu ra chuẩn trước khi lệnh trong 
- Sự khác nhau của | và <
  + Nối lệnh với lệnh
  + Nối file với lệnh1

