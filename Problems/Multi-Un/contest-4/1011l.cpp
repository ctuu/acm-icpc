    "code-runner.executorMap": {
        "cpp": "cls; cd $dir; g++ $fileName -o $fileNameWithoutExt -std=c++11 -lm; .\\$fileNameWithoutExt.exe",
        "c": "cls; cd $dir; gcc $fileName -o $fileNameWithoutExt -std=c11 -lm; .\\$fileNameWithoutExt.exe"
    },