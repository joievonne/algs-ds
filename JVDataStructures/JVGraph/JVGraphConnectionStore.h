#import <Foundation/Foundation.h>
#import "JVGraphConnectionStoreProtocol.h"

NS_ASSUME_NONNULL_BEGIN

// The Graph Connection Store has the task of keeping track of
// adjacency metrics in various forms and is able convert between
// these forms when appropriate (context being of time-space
// efficiency).
@interface JVGraphConnectionStore<NodeType> : NSObject

- (NSEnumerator *)adjacencyEnumerator;
- (BOOL)connectionExistsFromNode:(NodeType)node1
                          toNode:(NodeType)node2
                        directed:(BOOL)directed
                           value:(NSValue *)value;
@property(nonatomic, readonly) NSUInteger connectionCount;
@property(nonatomic, readonly) NSUInteger nodeCount;
- (NSUInteger)degreeOfNode:(NodeType)node;
@property(nonatomic, readonly) NSUInteger directedConnectionCount;
- (NSUInteger)indegreeOfNode:(NodeType)node;
- (instancetype)initWithNode:(NodeType)node1
              adjacentToNode:(NodeType)node2
                    directed:(BOOL)directed
                       value:(NSValue *)value;
- (NSEnumerator *)nodeEnumerator;
- (NSUInteger)outdegreeOfNode:(NodeType)node;
- (void)removeNode:(NodeType)node;
- (void)removeNode:(NodeType)node1
    adjacentToNode:(NodeType)node2
          directed:(BOOL)directed
             value:(NSValue *)value;
- (void)setNode:(NodeType)node1
 adjacentToNode:(NodeType)node2
       directed:(BOOL)directed
          value:(NSValue *)value;
@property(nonatomic, readonly) NSUInteger undirectedConnectionCount;
@property(nonatomic, readonly) NSUInteger uniqueIncidenceCount;

@end

@interface JVGraphConnectionStore<NodeType> (JVGraphExtendedConnectionStore)

- (BOOL)connectionExistsFromNode:(NodeType)node1 toNode:(NodeType)node2;
- (BOOL)connectionExistsFromNode:(NodeType)node1 toNode:(NodeType)node2 directed:(BOOL)directed;
- (BOOL)connectionExistsFromNode:(NodeType)node1 toNode:(NodeType)node2 value:(NSValue *)value;

- (void)removeNode:(NodeType)node1 adjacentToNode:(NodeType)node2;
- (void)removeNode:(NodeType)node1 adjacentToNode:(NodeType)node2 directed:(BOOL)directed;
- (void)removeNode:(NodeType)node1 adjacentToNode:(NodeType)node2 value:(NSValue *)value;

- (void)setNode:(NodeType)node1 adjacentToNode:(NodeType)node2;
- (void)setNode:(NodeType)node1 adjacentToNode:(NodeType)node2 directed:(BOOL)directed;
- (void)setNode:(NodeType)node1 adjacentToNode:(NodeType)node2 value:(NSValue *)value;

@end

@interface JVGraphConnectionStore<NodeType> (JVGraphConnectionStoreCreation)

- (instancetype)initWithNode:(NodeType)node1 adjacentToNode:(NodeType)node2;
- (instancetype)initWithNode:(NodeType)node1 adjacentToNode:(NodeType)node2 directed:(BOOL)directed;
- (instancetype)initWithNode:(NodeType)node1 adjacentToNode:(NodeType)node2 value:(NSValue *)value;

+ (instancetype)store;
+ (instancetype)storeWithNode:(NodeType)node1 adjacentToNode:(NodeType)node2;
+ (instancetype)storeWithNode:(NodeType)node1 adjacentToNode:(NodeType)node2 directed:(BOOL)directed;
+ (instancetype)storeWithNode:(NodeType)node1 adjacentToNode:(NodeType)node2 value:(NSValue *)value;
+ (instancetype)storeWithNode:(NodeType)node1
			   adjacentToNode:(NodeType)node2
					 directed:(BOOL)directed
						value:(NSValue *)value;

@end

NS_ASSUME_NONNULL_END