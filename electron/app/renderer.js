// Simulated user
const username = "JohnDoe"; // Replace with actual user logic
document.getElementById('username').textContent = `Welcome, ${username}`;

// Medication list
let medications = [];

function renderTable() {
  const tbody = document.querySelector('#medTable tbody');
  tbody.innerHTML = '';
  medications.forEach((med, idx) => {
    const tr = document.createElement('tr');
    tr.innerHTML = `
      <td>${med.name}</td>
      <td>${med.dosage}</td>
      <td>${med.frequency}</td>
      <td>${med.total}</td>
      <td>${med.fillDate}</td>
      <td>
        <button class="remove-btn" onclick="removeMedication(${idx})">Remove</button>
      </td>
    `;
    tbody.appendChild(tr);
  });
}

function openAddModal() {
  document.getElementById('addModal').style.display = 'flex';
}

function closeAddModal() {
  document.getElementById('addModal').style.display = 'none';
  document.getElementById('addMedForm').reset();
}

function manageUsers() {
  alert("Manage Family Members feature is not implemented yet.");
}

document.getElementById('addMedForm').addEventListener('submit', function(e) {
  e.preventDefault();
  const med = {
    name: document.getElementById('medName').value,
    dosage: document.getElementById('medDosage').value,
    frequency: document.getElementById('medFrequency').value,
    total: document.getElementById('medTotal').value,
    fillDate: document.getElementById('medFillDate').value
  };
  medications.push(med);
  renderTable();
  closeAddModal();
});

function removeMedication(index) {
  medications.splice(index, 1);
  renderTable();
}

// NEW: Electron IPC call
async function runBackend() {
  const outputElem = document.getElementById('backendOutput');
  outputElem.textContent = "Running MedicationManager.exe...";
  try {
    const result = await window.medAPI.runMedicationManager();
    outputElem.textContent = result;
  } catch (err) {
    outputElem.textContent = 'Error running backend: ' + err;
  }
}

document.getElementById('run-backend').addEventListener('click', runBackend);

// Initial render
renderTable();
