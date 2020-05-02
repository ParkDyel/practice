# Server Monitoring

## 목표

AWS 상의 리소스들에 대한 모니터링

## 모니터링 툴

### CloudWatch

AWS에서 제공하는 기본적인 모니터링 툴. 기본 지표 외에도 클라이언트에 agent를 설치하여 추가적인 지표를 획득 할 수 있다.

### Zabbix

오픈 소스의 모니터링 툴로 서버를 생성하고, 클라이언트에 agent를 설치하여 서버로 지표를 전송한다.

php 어드민 툴을 이용하여 GUI로 설정가능하며 불편한 대시보드는 별도의 툴([grafana](https://grafana.com/))을 연결하여 개선할 수 있다.

#### 참고 문서

[구축 (1/2)](https://steven-life-1991.tistory.com/35)
[구축 (2/2)](https://steven-life-1991.tistory.com/36)
[대시보드](https://heesy.tistory.com/60)

## 모니터링 툴 비교

| Vender | CloudWatch      | Zabbix                     |
| :----: | --------------- | -------------------------- |
| 도입 장점  | AWS 기본 서비스 툴    | 모든 과정이 무료                  |
| 우려되는 점 | 1. 지표별로 부과되는 요금 | 1. 별도의 서버를 운영해야 함          |
|        | 1. 모니터링 기간 (2주) | 2. RDS에 대한 지표 제공 불가능       |
|        | 1. 사용자 지표       | 3. Zabbix 서버에 대한 모니터링이 필요함 |
|        |                 | 4. 로그 관리 (DB 구축)           |

1. CloudWatch에 대한 비교 분석

   - AWS 기본 서비스라는 것이 어떤 장점이 있는가?
       - AWS 서비스 상에서 모든 것이 확인 가능함.
       - 인프라 서비스와 모니터링 툴의 일원화
   - [지표별로 부과되는 요금(기준 월별)이 적절한가?](https://aws.amazon.com/ko/cloudwatch/pricing/)
        - 지표 : 0.3 $/지표
        - API : 0.01 $/1000개의 지표
        - 대시보드 : 3 $/대시보드
        - alarm : 0.1$/Alarm

        ```txt
        총 지표 수 = 인스턴스당 지표 5개 * 인스턴스 10개 = 지표 50개
        월별 CloudWatch 지표 요금(사용자 지정 지표당 0.30 USD) = 50 * 0.30 USD = 15 USD

        월별 총 분 수 = 60 * 24 * 30 = 42,300분
        총 API 요청 수 = 인스턴스 10개 * (42,300분/5분) = 요청 84,600개
        처음 1,000,000개의 API 요청 = 0 USD

        월별 CloudWatch 요금 = 15 USD + 0 USD = 월별 15 USD
        ```

2. Zabbix

   - 서버 운용비용은?
       - 예약 인스턴스를 사용하면 최소한의 요금이 부과됨.
   - Zabbix 서버를 CloudWatch로 모니터링 해야함.
       - 모니터링의 이원화
   - RDS에 대한 지표는 제공 불가능한가?
       - [CloudWatch와 MySQL을 이용한 RDS 모니터링](https://www.joinc.co.kr/w/Site/QOS/Monitering_Tool/zabbix/RDSMonitoring) : 이건 조금 더 복잡한 ..
