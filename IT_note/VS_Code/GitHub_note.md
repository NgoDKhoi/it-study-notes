# Git note
- `git checkout <tên nhánh>`: di chuyển tới nhánh  
- `git checkout -b DKhoi`: tạo nhánh DKhoi và di chuyển tới nó
- `git pull origin main`: cập nhật nhánh `main`, kéo phiên bản mới nhất của nhánh `main` từ github về máy
- `git branch -d DKhoi`: Xóa nhánh DKhoi ở trên mấy bạn



git reset  
git log --oneline  

# Cách sử dụng
- Bước 1: Tải code về và cập nhật code mới nhất  
`git clone https://github.com/NgoDKhoi/Meo_Boom.git`  
`git checkout main`  
`git pull origin main`  

- Bước 2: Tạo nhánh mới và làm việc  
`git checkout -b DKhoi`  
  + Sau đó mở Unity lên edit, và khi đã edit xong thì tới bước 3  
- Bước 3: Đẩy code lên nhánh của mình ở github  
`git add .`  
`git commit -m "DKhoi them tinh nang giao dien ban choi"`  
`git push -u origin DKhoi`  
  + Sửa cái gì thì ghi tên + nội dung chỉnh sửa, sau một hoặc nhiều lần commit bạn thấy code ở nhánh mình đã ổn thì đến bước 4 gộp với nhánh main để mọi người có thể lấy code từ nhánh main về 

- Bước 4: Tạo yêu cầu gộp nhánh của mình với main
  + Vào github của dự án, chọn `Compare & pull request`
  + Viết tiêu đề, mô tả rõ ràng rồi nhấn `Create pull request`

- Bước 5: Xóa nhánh trên máy cho đỡ rối (C)  
`git checkout main`  
`git pull origin main`  
`git branch -d DKhoi`  

## Nếu ở bước 2 code bug nhiều quá, muốn làm lại từ đầu
- Bước 3: Xóa nhánh hiện tại  
`git checkout main`  
`git branch -d DKhoi`
- Bước 4: Tải code trên nhánh main về và tạo nhánh mới rồi làm lại  
`git checkout -b DKhoi`


  
  
  
# Lưu ý
KHÔNG BAO GIỜ hai người cùng sửa 1 file Scene hoặc 1 file Prefab cùng một lúc. Hãy giao tiếp với nhau trước khi làm!  

    
     
git remote add origin https://github.com/NgoDKhoi/Ten_Repo.git  
git config --global user.name "Ten_Github"  
git config --global user.email "Ten_Gmail@gmail.com"







