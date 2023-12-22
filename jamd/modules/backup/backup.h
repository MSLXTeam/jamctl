#pragma once

#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <openssl/evp.h>
#include <openssl/sha.h>
#include <spdlog/spdlog.h>
#include <mutex>
#include <future>
#include <json/json.h>

namespace fs = std::filesystem;

using String = std::string;
using HashBuffer = std::vector<unsigned char>;
using JsonValue = Json::Value;
using Path = fs::path;
using LockGuard = std::lock_guard<std::mutex>;
using Future = std::future<void>;
using ios = std::ios;
using ofstream = std::ofstream;

// 声明全局锁
extern std::mutex log_mutex;

// 进度文件路径
extern const std::string progress_file;

// 函数声明

// 读取进度文件
JsonValue load_progress();

// 保存进度文件
void save_progress(const JsonValue &progress);

// 计算文件的 SHA-256 哈希值
void calculate_sha256_hash(const Path &filename, HashBuffer &outputBuffer);

// 复制文件
void b_copy_file(const Path &src, const Path &dst);

// 判断文件是否已修改
bool is_file_modified(const Path &srcPath, const JsonValue &progress);

// 更新进度文件
void update_progress(const Path &srcPath, const HashBuffer &hash, JsonValue &progress);

// 处理单个文件
void process_file(const Path &srcPath, const Path &dstPath, JsonValue &progress);

// 增量备份
void incremental_backup(const Path &sourceDir, const Path &destDir);