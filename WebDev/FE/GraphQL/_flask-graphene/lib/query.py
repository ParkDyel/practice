import graphene

class Query(graphene.ObjectType):
    hello = graphene.String(name=graphene.String(default_value="stranger"))

    @staticmethod
    def resolve_hello(self, info, name):
        return 'Hello ' + name