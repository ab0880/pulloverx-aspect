# PullOver X（rootless）

PullOver X is maintained by **mlgm** and based on PullOver Pro by Will Smillie
(`c1d3rDev`). This fork is configured for standard **rootless** jailbreaks
such as Dopamine/Fugu15 on arm64/arm64e devices.

## 本仓库改动

- 移除 RootHide `libroothide`、RootHide devkit 和 `@import <roothide.h>` 依赖。
- 使用标准 rootless 包路径：所有文件安装到 `/var/jb/...`。
- Debian 架构改为 `iphoneos-arm64`；二进制编译 `arm64 arm64e`。
- `build.sh` 默认并且只接受 `rootless`，同时构建并打包 tweak 与偏好设置。
- GitHub Actions 自动安装 Theos、iOS SDK、ldid、dpkg，并上传 `.deb` artifact。

## GitHub Actions 编译操作指南

### 1. Fork 项目

1. 打开本项目 GitHub 页面，点击右上角 **Fork**。
2. 选择自己的 GitHub 账号，建议保留仓库名称 `pulloverx-aspect`。
3. 进入 Fork 后打开 **Settings → Actions → General**，确认允许运行 Actions。

### 2. 启动编译

把修改推送到 Fork 的 `main` 分支会自动编译；也可以手动执行：

1. 打开 Fork 仓库的 **Actions**。
2. 选择 **Build PullOver X (rootless)**。
3. 点击 **Run workflow → Run workflow**。
4. 等待 job 完成，在页面底部 **Artifacts** 下载 `pulloverx-rootless-deb`。

### 3. 安装到 Dopamine/rootless 设备

将下载的 `.deb` 传到设备后，在终端执行：

```sh
dpkg -i com.mlgm.pulloverx_*_iphoneos-arm64.deb
# 或者使用 Sileo/Zebra/安装器打开该 deb
```

安装后执行一次 userspace reboot/respring。该包依赖
`mobilesubstrate` 和 `preferenceloader`，请先确认对应 rootless 版本已经安装。

## 本地编译

需要 macOS、Xcode、Theos、ldid 和 dpkg：

```sh
export THEOS=/opt/theos
./build.sh rootless release
# 输出：packages/com.mlgm.pulloverx_1.96_iphoneos-arm64.deb
```

调试包：

```sh
./build.sh rootless debug
```

## 常见问题

- **没有生成 artifact**：打开 Actions 的失败步骤，优先检查 Xcode/SDK 下载或 Theos 依赖。
- **安装后设置里没有条目**：确认 `preferenceloader` 已安装，并执行 respring。
- **设备提示架构不匹配**：确认下载的是 `iphoneos-arm64` 包，而不是旧的 arm64e/roothide 包。
- **不要在 rootless 设备上安装旧 roothide 包**：RootHide 与标准 rootless 的路径、链接方式不同。

## License

GNU General Public License v3.0。第三方组件仍以其各自许可证为准。
