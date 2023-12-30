# Authors: Antonio Cabrera y Alejandro Gómez
# Group: 3º MAIS  2023/2024
# Description: 

# desinstalar Docker y Kubernetes

sudo apt purge docker*
sudo rm -r /etc/docker/
sudo rm -r /etc/apt/sources.list.d/docker.list 
sudo rm -r /etc/apt/sources.list.d/kubernetes.list
sudo apt purge containerd
sudo rm -r /etc/containerd

# apagar la swap
sudo sed -i '/ swap / s/^\(.*\)$/#\1/g' /etc/fstab
sudo swapoff -ap.img

# <-- Instalaciones: -->
sudo apt get update

# instalar Docker
sudo apt install docker.io
systemctl enable docker
systemctl restart docker

# instalar Kubernetes (kubeadm, kubelet y kubectl)
sudo apt-get install -y apt-transport-https ca-certificates curl gpg
curl -fsSL https://pkgs.k8s.io/core:/stable:/v1.29/deb/Release.key | sudo gpg --dearmor -o /etc/apt/keyrings/kubernetes-apt-keyring.gpg
echo 'deb [signed-by=/etc/apt/keyrings/kubernetes-apt-keyring.gpg] https://pkgs.k8s.io/core:/stable:/v1.29/deb/ /' | sudo tee /etc/apt/sources.list.d/kubernetes.list
sudo apt-get update
sudo apt-get install -y kubelet kubeadm kubectl
sudo apt-mark hold kubelet kubeadm kubectl