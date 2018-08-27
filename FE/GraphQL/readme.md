# GraphQL

## GraphQL은

__데이터를 질의하는 문법이다.__ 주로 서버에서 클라이언트로 데이터를 load하기 위해 사용된다. GraphQL은 다음과 같이 3가지 특징이 있다.

- Client가 필요한 데이터를 구체화 할 수 있다.
- multiple-soruces로부터 쉽게 데이터를 모을 수 있다.
- 데이터를 묘사하기 위해 type system을 사용한다.

GraphQL은 거대하고 성숙한 Facebook에서 시작되었고 사용되지만, 간단한 App에서도 전통적인 REST API의 제한을 해소하기 위해 사용할 수 있다.

## 예를 들어

좋아요를 누른 유저의 프로필 목록을 가진 Port 목록을 보여주어야 할 때, 좋아요를 누른 유저 프로필 객체 배열을 포함한 posts API를 다루면 된다. 하지만 이를 모바일 환경에서 로드해야 하는 경우 한 번에 모든 데이터를 로드하면 속도가 느려지므로, 두 개의 endpoint(likes, posts)로 분리한다.

단순한 경우에는 위와 같이 해결될 수 있지만 많은 데이터 소스와 API 클라이언트를 관리해야 하는 경우에는 한계에 부딪치게 된다.

## 해결책

많은 'dump' endpoint 대신에 복잡한 쿼리를 다룰 수 있고, 클라이언트의 요청이 어떠한 모양이든지 데이터를 출력할 수 있는 하나의 'smart' endpoint를 제공한다.

## 비교

- GraphQL vs REST API

|GraphQL|RESTful|
|:-:|:-:|
|서로 다른 모양의 요청에 대한 응답 가능|Caching|
|CRUD 기능|File 등 비 text|
||정형성 요청|


## 예제

GraphQL API는 3개의 중요 요소로 구성된다.

- schema
- queries
- reslvers

### Summury

- Query : 읽기작업을 하는 GraphQL문을 의미한다.
    - field : query에 있는 값(속성)
- Mutation : 데이터 수정작업을 하는 GraphQL문을 의미한다.
- schema : Query와 Mutation의 retrun type과 arguments type 및 custom type, custom interface, enum type 등과 input value의 default값 등을 정의한 코드를 의미한다.
- resolver : schema에서 정의된 Query와 Mutation의 구조에 맞추어 retrun type과 arguments type에 맞추어 설정한 코드를 의미한다.

### Query

```graphql
query {
    stuff
}
```

```graphql
query {
    stuff {
        eggs
        shirt
        pizza
    }
}
```

```graphql
query {
    posts {
        title
        body
        author {
            name
            avatarUrl
            profileUrl
        }
    }
}
```

```graphql
query {
    port(id: "123foo"){
        title
        body
        author {
            name
            avatarUrl
            profileUrl
        }
    }
}
```

```graphql
query getMyPost($id: String){
    port(id:$id){
        title
        body
        author {
            name
            avatarUrl
            profileUrl
        }
    }
}
```

```graphql
`OperationType=query` `OperationName=HeroNameAndFriends` `Variable defintions=($episode: Episode)`{
    hero(episode: $episode){
        name
    }
}
```

### Resolvers

Resolver는 GraphQL에게 주어진 필드에 상응하는 데이터를 가져올 방법과 위치를 알려준다.

```graphql
Query: {
  post(root, args) {
    return Posts.find({ id: args.id });
  }
}
```

```graphql
Query: {
  post(root, args) {
    return Posts.find({ id: args.id });
  }
},
Post: {
  author(post) {
    return Users.find({ id: post.authorId})
  }
}
```

### Mutations

```python
import graphene

class CreatePerson(graphene.Mutation):
    class Arguments:
        name = graphene.String()

    ok = graphene.Boolean()
    person = graphene.Field(lambda: Person)

    def mutate(self, info, name):
        person = Person(name=name)
        ok = True
        return CreatePerson(person=person, ok=ok)

class Person(graphene.ObjectType):
    name = graphene.String()
    age = graphene.Int()

class MyMutations(graphene.ObjectType):
    create_person = CreatePerson.Field()

# We must define a query for our schema
class Query(graphene.ObjectType):
    person = graphene.Field(Person)

schema = graphene.Schema(query=Query, mutation=MyMutations)
```

```graphql
mutation myFirstMutation {
    createPerson(name:"Peter") {
        person {
            name
        }
        ok
    }
}
```


## 실험환경

1. [Apollo launchpad](https://launchpad.graphql.com)

1. [Graphene](http://graphene-python.org/)


## 참고목록

- [graphql.org](https://graphql.org/learn/)
- [http://www.holaxprogramming.com/](http://www.holaxprogramming.com/2018/01/20/graphql-vs-restful-api/)
- [freecodecamp](https://medium.freecodecamp.org/so-whats-this-graphql-thing-i-keep-hearing-about-baf4d36c20cf)
- [Graphene Flask+SQLAlchemy](http://docs.graphene-python.org/projects/sqlalchemy/en/latest/)