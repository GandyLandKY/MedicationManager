ipcMain.handle('run-medication-manager', async () => {
  return new Promise((resolve, reject) => {
    const exePath = path.join(__dirname, 'app', 'MedicationManager.exe');
    execFile(exePath, (error, stdout, stderr) => {
      if (error) {
        reject(stderr);
      } else {
        resolve(stdout);
      }
    });
  });
});
