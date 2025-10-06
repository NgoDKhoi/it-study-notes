# Ghi chú về ngôn ngữ Move

### Package
- cd vào folder gõ `sui move new <name_package>` để tạo gói trong folder
- Package chứa nhiều `module` và trong phạm vi các fun độc lập với nhau
- `Move.toml`: Là một tệp kê khai của gói, mô tả gói và các phần phụ thuộc của nó
  + `[package]`: Chứa thông tin mô tả cơ bản về gói, tên, phiên bản và phiên bản của move
  + `[dependencies]`:
  + `[addresses]`: thêm bí danh cho địa chỉ
- `sources`: Là thư mục báo gồm các mô đun. `Module` là các phần triển khai cụ thể của hợp đồng thông minh.
- `tests`: Là thư mục chứa mã kiểm tra gói
### Module
- Cách khai báo:
  `module <address>::<name_module> {...}`
- `<address>`: là địa chỉ của gói chứa module
- Bên trong module là các thành viên của nó:
  + `use`: đại diện cho module được nhập từ nội dung khác
  + `type`: đại diện cho các kiểu được định nghĩa trong module 
  + `function`: đại diện cho các hàm trong module
  + `contanst`: đại diện cho các hằng số trong module
- Lưu ý: `name_module` phải ghi thường, gạch dưới. Và các module mặc định là `private` ,muốn sử dụng thì phải thêm từ khóa `public` ở trước.

