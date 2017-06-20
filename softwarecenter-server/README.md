## 软件中心服务器数据库表结构
### 产品表
**sc_product**

| 产品ID | 当前ReleaseID | 分类ID | 图标URL (同Release) | 产品名 | 厂家名 | 厂家主页 | 产品说明 | 产品总评分 | 评分数量 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--| :--- | :--- |
| ProductID | ReleaseID |  CategoriesID | IconURL | ProductName | VendorName | URL | ProductDescription | ProductGrade | GradeCount |

### 产品发布表
**sc_prelease**

| 发布ID | 产品ID | 版本 | 图标URL | 下载URL | 更新记录 | 包类型 | 安装包大小 | 发布评分 |评分数量 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| ReleaseID | ProductID | Version | IconURL | DownloadURL | ChangeLog | PackageSize | PackageType | ReleaseGrade | GradeCount |

### 用户评论表
**sc_comment**

| 评论ID | 产品ID | 发布ID | 用户ID | 评论内容 | 具体评分 | 评论时间 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| CommentID | ProductID | ReleaseID | UseID | CommentText | CommentGrade | ComentDate |

### 产品截图表
**sc_screen_image**

| 截图ID | 产品ID | 发布ID | 截图URL |
| :--- | :--- | :--- | :--- |
| ScreenImageID | ProductID | ReleaseID | ScreenImageURL |

### 产品分类表
**sc_categories**

| 分类ID | 分类名 |
| :--- | :--- |
| CategoriesID | CategoriesName |

### 热门推荐
**sc_recommend**

| 产品ID | 排序优先级 |
| :--- | :--- | 
| ProductID | Priority |

### 横幅内容
**sc_banners**

| 产品ID | 排序优先级 |
| :--- | :--- | 
| ProductID | Priority |

### 用户表
**sc_user**

| 用户ID | 用户名 | 用户头像URL | 用户邮件地址|
| :--- | :--- | :--- | :--- |
| UserID |  UserName| UserAvatarURL |  UserMailURL |
