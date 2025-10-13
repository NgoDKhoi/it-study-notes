# Window form note
- Có thể double click vào control để tạo hàm cho control đó trong file form1.cs
- 

## Form
- Tên nên bắt đầu bằng `frm`
- Một số thuộc tính quan trọng của form  

|  STT |   Thuộc tính   |  Nội dung |
|------|----------------|-----------|
|   1   |   StatPosition    |   Định vị vị trí form khi mới open |  
|   2   |   WindowState     |   Chế độ của form khi mới open (full screen, normal, dưới thanh taskbar)|  
|   3   |   Size            |   Kích cỡ form (kéo thả or nhập trực tiếp) |
|   4   |   MaximizeBox     |   False để ẩn ô vuông phóng to     |
|   5   |   MinimizeBox     |   False để ẩn ô vuông thu nhỏ |
|   6   |   AcceptButton    |   Chọn nút bấm thực hiện khi click `Enter` |
|   6   |   CancelButton    |   Chọn nút bấm thực hiện khi click `Esc` |
 
- Chúng ta có thể add thêm control bằng cách mở toolbox -> right click -> choose items
- Cách căn lề `control`: Giữu ctrl -> click vào master -> click những cái muốn căn lề theo master -> Format -> Align 
- Cách điều chỉnh thứ tự `Tab oder`: View -> Tab oder -> đè ctrl và chọn theo thứ tự

## Label
- Tên nên bắt đầu bằng `lbl`
- `Autosize`: tùy chỉnh kích thước (nếu chọn `false`)
- `Dock`: Chỉnh kích thước tràn ra cho bằng form

## Textbox
- Tên nên bắt đầu bằng `txt`
- `Multiline`: nội dung textbox cho phép dẫu xuống dòng (nếu chọn `true`)
- `ReadOnly`: textbox chỉ đọc, không chỉnh sửa được nội dung (nếu chọn `true`)
- `PasswordChar`: Nhập vào ký tự thay thế (ví dụ *)

## Button
- Tên nên bắt đầu bằng `btn`

## Message Box 
MessageBox.Show (
    message,
    title,
    MessageBoxButtons
    MessageBoxIcon
);

## Các lớp
- `OpenFileDialog`: ofd
  + .showDialog(): Hiển thị hộp thoại
  + .SafeFileName.ToString(): lấy tên file

- `FileStream`: fs
  + .Name.ToString(): lấy đường dẫn của file
  + .Length.ToString(): lấy kích thước của file
  + .SetLenght(): thay đổi kích thước File (truyền 0 là xóa toàn bộ nội dung file)          

- `StreamReader`: sr
  + .ReadToEnd(): đọc toàn bộ nội dung file từ đầu tới cuối

- `StreamWriter`: sw
  + .Write(content): ghi dữ liệu dạng text vào file



## Các hàm 

