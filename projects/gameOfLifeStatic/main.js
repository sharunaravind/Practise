const { app, BrowserWindow } = require("electron");

let mainWindow;

app.on("ready", () => {
  mainWindow = new BrowserWindow({
    width: 800, // Set the initial width
    height: 600, // Set the initial height
    webPreferences: {
      contextIsolation: true, // Security best practice
      nodeIntegration: false, // Security best practice
    },
  });

  // Load your HTML file
  mainWindow.loadFile("index.html");
});

app.on("window-all-closed", () => {
  // Close the app when all windows are closed (except on macOS)
  if (process.platform !== "darwin") {
    app.quit();
  }
});

app.on("activate", () => {
  // Re-create a window in the app when the dock icon is clicked (macOS)
  if (BrowserWindow.getAllWindows().length === 0) {
    mainWindow = new BrowserWindow({
      width: 800,
      height: 600,
      webPreferences: {
        contextIsolation: true,
        nodeIntegration: false,
      },
    });
    mainWindow.loadFile("index.html");
  }
});
