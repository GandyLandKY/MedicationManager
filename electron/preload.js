// preload.js
const { contextBridge, ipcRenderer } = require('electron');

contextBridge.exposeInMainWorld('medAPI', {
  /**
   * Runs the MedicationManager.exe and returns its stdout as a Promise<string>
   */
  runMedicationManager: () => ipcRenderer.invoke('run-medication-manager')
});
