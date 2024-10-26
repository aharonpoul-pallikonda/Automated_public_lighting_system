window.onload = function() {
  setInterval(getData, 5000); // Fetch data every 5 seconds
};

function getData() {
  fetch('/data')
    .then(response => response.json())
    .then(data => {
      document.getElementById('status').textContent = data.status;
      document.getElementById('voltage').textContent = data.voltage;
      document.getElementById('fault').textContent = data.fault;
    })
    .catch(error => console.error('Error:', error));
}
