# Docker란

## Docker

Docker란 가상 환경을 제공함에 있어 Host OS 위에서 공유 될 수 있는 커널 부분은 Host OS 영역과 공유하고 그 이외의 커널 부분과 필요한 패키지들을 패키징한다.

### 쉘 명령어 인자

```bash
docker exec
docker exec -it
```

```bash
docker logs --tail 50 --follow --timestamps `ContainerName`
```

## DockerFile

이미지 빌드 용 DSL(Domain Specfic Langugae )

## docker-compose

docker-compose는 복수의 컨테이너 Docker를 정의하고 실행하기 위한 도구이다.

### 쉘 명령어 인자

```bash
docker-compose build
docker-compose up
docker-compose up -d
```

### 내부 변수

```yml
```

### 예시

## kitematic

## kubernetes