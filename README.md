# ShadowAC1 - USN Journal Tampering Detector

A comprehensive Windows forensic tool for detecting tampering with NTFS USN (Update Sequence Number) Journals. Helps identify potential anti-forensic activities and system manipulation attempts.

## 🔍 Overview

ShadowAC1 analyzes NTFS USN Journals to detect evidence of tampering, deletion, clearing, or manipulation. USN Journals are critical for forensic analysis as they maintain a record of file system changes that attackers often target to hide their activities.

## ✨ Features

- **Journal Deletion Detection** - Identifies missing or deleted USN journals
- **Journal Clearing Detection** - Detects cleared or reset journal entries  
- **Timestamp Analysis** - Compares USN records with MFT timestamps
- **Gap Detection** - Identifies suspicious gaps in USN sequences
- **Event Log Correlation** - Cross-references with Windows event logs
- **Baseline Comparison** - Tracks changes over time
- **Multi-Volume Support** - Analyzes all NTFS volumes on the system

## 🚀 Usage

```bash
ShadowAC1.exe
```

The tool automatically performs a 5-phase analysis:
1. **USN Journal Analysis**
2. **Event Log Analysis**  
3. **Journal Manipulation Detection**
4. **Baseline Comparison**
5. **Report Generation**

## 📊 Evidence Types

| Type | Description | Severity |
|------|-------------|----------|
| `JOURNAL_DELETED` | USN Journal files missing | **Critical** |
| `JOURNAL_CLEARED` | Journal entries cleared | **High** |
| `SUSPICIOUS_GAPS` | Large gaps in USN sequences | **Medium** |
| `FSUTIL_COMMAND` | Suspicious fsutil commands | **High** |

## 📋 Requirements

- Windows 7/Server 2008 or later
- Administrator privileges (recommended)
- NTFS file systems
- Visual C++ Runtime

## 🔧 Compilation

```bash
cl /EHsc TamperingDetector.cpp UsnAnalyzer.cpp EventAnalyzer.cpp ConsoleColors.cpp -o ShadowAC1.exe
```

## 📄 Output

- **Console**: Real-time analysis with color-coded severity levels
- **Report**: `ShadowAC1_Report_[timestamp].txt` - Detailed findings
- **Baseline**: `ShadowAC1_Baseline.dat` - Historical journal state

## 🎯 Use Cases

- **Digital Forensics** - Incident response and malware analysis
- **Security Monitoring** - Anti-forensic detection
- **System Administration** - Integrity verification and compliance

## ⚠️ Security Notice

This tool performs low-level file system analysis and is designed for legitimate forensic and security purposes only. Use responsibly and ensure proper authorization.

## 📝 License

Provided for educational and professional forensic purposes. Use in accordance with applicable laws and regulations.
