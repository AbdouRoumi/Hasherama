# Hasherama

## [![Typing SVG](https://readme-typing-svg.demolab.com?font=JetBrains+Mono&weight=2000&pause=1000&width=435&lines=Welcome+to+Hasherama+Repo!!!;Hash+malware+strings+efficiently;Advanced+string+analysis+tool;Research-grade+hashing+toolkit)](https://git.io/typing-svg)

## Overview

Welcome to the **Hasherama** repository! This project is a specialized string hashing toolkit designed for malware researchers and security professionals. It implements multiple hashing algorithms commonly used in malware analysis and research, derived from the VX Underground collection. The tool supports both ASCII and Unicode strings, making it essential for analyzing various types of malware strings, identifiers, and patterns.

This toolkit is specifically crafted for security research purposes, providing implementations of hashing algorithms frequently encountered in malware samples and security research.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Example Output](#example-output)
- [Research Applications](#research-applications)
- [Contributing](#contributing)
- [License](#license)

## Features

- Implementation of hashing algorithms commonly found in malware:
  - Djb2 (ASCII/Unicode) - Often used in string table lookups
  - FowlerNollVo Variant 1a - Popular in malware string obfuscation
  - LoseLose - Seen in basic string hashing implementations
  - Sdbm - Used in various malware families
  - Jenkins One-at-a-Time (32-bit) - Common in advanced string obfuscation
  - Unknown Generic Hash 1 - Documented from malware samples
- Full Unicode support for international malware analysis
- Clean, documented implementations for research purposes
- Memory-efficient processing
- Windows API compatible

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/Hasherama.git
   ```
2. Open the project in Visual Studio.
3. Build the project in Debug or Release mode.

## Usage

1. Compile the program.
2. Use in your malware analysis tools or scripts:
   ```cpp
   // Hash potentially malicious API strings
   DWORD apiHash = HashStringDjb2A("CreateRemoteThread");

   // Hash Unicode command strings
   DWORD cmdHash = HashStringDjb2W(L"cmd.exe /c whoami");

   // Compare with known malware hashes
   if (HashStringJenkinsOneAtATime32BitA(suspiciousString) == knownMalwareHash) {
       // Handle detection
   }
   ```

## Example Output

```
=== ASCII String Tests ===
Input: "E1B1gR0m4"
Djb2:              0xE286DCF8
FowlerNollVo:      0x52E9ECF8
LoseLose:          0x00000273
Sdbm:              0xE53C6FF1
UnknownGeneric:    0x557C10A4
JenkinsOneAtATime: 0x24C0A73A

=== Unicode String Tests ===
Input: "ElB1gR0m4"
Djb2:              0x55B2ECD3
FowlerNollVo:      0xD5FFC641
LoseLose:          0x000002AE
Sdbm:              0x7A5066F6
UnknownGeneric:    0x057C14F4
JenkinsOneAtATime: 0x3BD3D1A3

Press Enter to quit...
```

## Research Applications

- Malware Family Classification
- String Obfuscation Analysis
- API Function Hashing Detection
- Malware Configuration Extraction
- Indicator of Compromise (IoC) Generation
- Malware Family Correlation

## Contributing

Contributions from malware researchers and security professionals are welcome! If you've encountered new hashing algorithms in your research or want to improve existing ones, feel free to open an issue or submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE.txt).

## Disclaimer

This tool is intended for security research and malware analysis purposes only. Users are responsible for ensuring compliance with applicable laws and regulations in their jurisdiction.

---
**Happy Hunting! 🔍**

> *"Understanding malware hashing techniques is crucial for modern threat analysis."*
